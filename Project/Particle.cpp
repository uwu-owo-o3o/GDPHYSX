
#include "Particle.hpp"

void Particle::UpdatePosition(float deltaTime) {
	this->position += (velocity * deltaTime) + (this->acceleration * deltaTime * deltaTime) / 2.f;

	Vector3 angularV = AngularVelocity * deltaTime;
	float angleMag = angularV.Magnitude();
	angularV.Normalize();

	Vector3 MagDir = angularV;
	if (angleMag != 0) {
		glm::quat rotBy = glm::rotate(glm::mat4(1.0f), angleMag, (glm::vec3)MagDir);
		this->Rotation = glm::toMat4(glm::toQuat(this->Rotation) * rotBy);
	}
}

void Particle::UpdateVelocity(float deltaTime) {
	this->acceleration += accumulatedForce / mass;
	this->velocity += this->acceleration * deltaTime;
	this->velocity *= powf(damping, deltaTime);

	float mI = MomentOfInertia();
	AngularVelocity += accumulatedTorque * deltaTime * ((float)1 / mI);
	AngularVelocity = AngularVelocity * powf(AngularDamping, deltaTime);
}

void Particle::Update(float deltaTime) {
	this->UpdatePosition(deltaTime);
	this->UpdateVelocity(deltaTime);

	this->ResetForce();

	if (this->lifeTicks >= this->lifeSpan) {
		this->Destroy();
	}

	this->lifeTicks += deltaTime;
}

void Particle::setPosition(Vector3 position) {
	this->position = position;
}

void Particle::setVelocity(Vector3 velocity) {
	this->velocity = velocity;
	this->initialVelocity = velocity;
}

void Particle::setAcceleration(Vector3 acceleration) {
	this->acceleration = acceleration;
}

void Particle::Instantiate() {
	this->isDestroyed = false;
}

void Particle::Destroy() {
	this->isDestroyed = true;
}

bool Particle::IsDestroyed() {
	return this->isDestroyed;
}

void Particle::AddForce(Vector3 force) {
	this->accumulatedForce += force;
}

void Particle::ResetForce() {
	this->accumulatedForce = Vector3::zero;
	this->acceleration = Vector3::zero;
	this->accumulatedTorque = Vector3::zero;
}

float Particle::MomentOfInertia() {
	return ((float)2 / 5) * mass * radius * radius;
}

void Particle::AddForceAtPoint(Vector3 force, Vector3 particle) {
	this->AddForce(force);
	this->accumulatedTorque = particle.Cross(force, this->accumulatedTorque);
}