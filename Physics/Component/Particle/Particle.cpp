#include "Particle.hpp"

using namespace component;

Particle::Particle() : CPosition(0.0f, 0.0f, 0.0f), CVelocity(0.0f, 0.0f, 0.0f), CAcceleration(0.002f, 0.0f, 0.0f), CAccumulatedForce(0, 0, 0) {
	this->mass = 0;
	this->name = "ball";
	this->isDestroyed = false;
	this->time = 0.0f;
	this->magnitudeVelocity = 0.0f;
}

void Particle::UpdatePosition(float time) {
	//this->CPosition.setCoordinates(this->CPosition.add(this->CVelocity) * time);
	glm::vec3 mUpdatedPosition = this->CPosition.getCoordinates() + (this->CVelocity.getCoordinates() * time) + (1.0f / 2.0f) * (this->CAcceleration.getCoordinates() * time * time);
	
	//this->CAcceleration.setCoordinates(this->CAcceleration.scalarMultiply(time * time));
	//this->CAcceleration.setCoordinates(this->CAcceleration.scalarMultiply(1.0f/2.0f));

	//this->CVelocity.setCoordinates(this->CVelocity.scalarMultiply(time));
	//this->CPosition.setCoordinates(this->CPosition.add(this->CVelocity));
	//this->CPosition.setCoordinates(this->CPosition.add(this->CAcceleration));

	this->CPosition.setCoordinates(mUpdatedPosition);
	
}

void Particle::UpdateVelocity(float time) {

	glm::vec3 mAcceleration = this->CAccumulatedForce.getCoordinates() * (1 / this->mass);
	this->CAcceleration.setCoordinates(mAcceleration);
	
	glm::vec3 mUpdatedVelocity = this->CVelocity.getCoordinates() + (this->CAcceleration.getCoordinates() * time);
	glm::vec3 mUpdatedVelocity2 = this->CVelocity.getCoordinates() * powf(damping, time);
	this->CVelocity.setCoordinates(mUpdatedVelocity2);
}

void Particle::Update(float time) {
	this->UpdatePosition(time);
	this->UpdateVelocity(time);
	this->ResetForce();
}

void Particle::Destroy() {
	this->isDestroyed = true;
	//std::cout << "called destroy!" << std::endl;
}

bool Particle::checkIfDestroyed() {
	return this->isDestroyed;
}

void Particle::AddForce(Vector force) {
	glm::vec3 sumForce = this->CAccumulatedForce.getCoordinates() + force.getCoordinates();
	this->CAccumulatedForce.setCoordinates(sumForce);
}

void Particle::ResetForce() {
	this->CAcceleration = Vector(0, 0, 0);
	this->CAccumulatedForce = Vector(0, 0, 0);
}

Vector* Particle::getPosition() {
	return &this->CPosition;
}

void Particle::setPosition(Vector CVector) {
	this->CPosition = CVector;
}

Vector* Particle::getVelocity() {
	return &this->CVelocity;
}

void Particle::setVelocity(Vector CVector) {
	this->CVelocity = CVector;
}

Vector* Particle::getAcceleration() {
	return &this->CAcceleration;
}

void Particle::setAcceleration(Vector CVector) {
	this->CAcceleration = CVector;
}