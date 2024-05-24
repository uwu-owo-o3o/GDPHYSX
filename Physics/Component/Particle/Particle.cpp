#include "Particle.hpp"

using namespace component;

Particle::Particle() : CPosition(0.0f, 0.0f, 0.0f), CVelocity(0.0f, 0.0f, 0.0f), CAcceleration(0.0f, 0.0f, 0.0f) {
	this->mass = 0;
}

void Particle::UpdatePosition(float time) {
	//this->CPosition.setCoordinates(this->CPosition.add(this->CVelocity) * time);
	glm::vec3 mUpdatedPosition = this->CPosition.getCoordinates() + (this->CVelocity.getCoordinates() * time) + (1.0f / 2.0f) * (this->CAcceleration.getCoordinates() * time * time);
	this->CPosition.setCoordinates(mUpdatedPosition);
	
}

void Particle::UpdateVelocity(float time) {
	this->CAcceleration.setCoordinates(this->CAcceleration.getCoordinates() * time);
	this->CVelocity.setCoordinates(this->CVelocity.add(this->CAcceleration));
}

void Particle::Update(float time) {
	this->UpdatePosition(time);
}

Vector Particle::getPosition() {
	return this->CPosition;
}

void Particle::setPosition(Vector CVector) {
	this->CPosition = CVector;
}

Vector Particle::getVelocity() {
	return this->CVelocity;
}

void Particle::setVelocity(Vector CVector) {
	this->CVelocity = CVector;
}

Vector Particle::getAcceleration() {
	return this->CAcceleration;
}

void Particle::setAcceleration(Vector CVector) {
	this->CAcceleration = CVector;
}