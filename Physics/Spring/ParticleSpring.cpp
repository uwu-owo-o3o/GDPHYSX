#include "ParticleSpring.hpp"

using namespace component;

ParticleSpring::ParticleSpring(Particle* particle, float springconstant, float restlength) : otherParticle(particle) {
	this->springConstant = springconstant;
	this->restLength = restlength;
}

void ParticleSpring::UpdateForce(Particle* particle, float time) {
	Vector pos = *particle->getPosition();
	Vector force = Vector();

	force.setCoordinates(pos.getCoordinates() - otherParticle->getPosition()->getCoordinates());

	force.calculateMagnitude();
	float mag = force.getMagnitude();

	float springForce = -springConstant * abs(mag - restLength);

	force.calculateDirection();
	force.setCoordinates(force.getDirection());

	force.setCoordinates(force.getCoordinates() * springForce);

	particle->AddForce(force);
}