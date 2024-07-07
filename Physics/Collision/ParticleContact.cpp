#include "ParticleContact.hpp"

using namespace collision;

float ParticleContact::GetSeparatingSpeed() {
	Vector velocity = *particles[0]->getVelocity();
	if (particles[1]) {
		glm::vec3 vel = velocity.getCoordinates() - particles[1]->getVelocity()->getCoordinates();
		velocity.setCoordinates(vel);
		
	}

	return velocity.calculateDotProduct(contactNormal);
}

void ParticleContact::ResolveVelocity(float time) {
	float separatingSpeed = GetSeparatingSpeed();

	if (separatingSpeed > 0) {
		return;
	}

	float newSS = -restitution * separatingSpeed;
	float deltaSpeed = newSS - separatingSpeed;

	float totalMass = (float)1 / particles[0]->mass;
	if (particles[1]) {
		totalMass += (float)1 / particles[1]->mass;
	}

	if (totalMass <= 0) {
		return;
	}

	float impulse_mag = deltaSpeed / totalMass;
	Vector Impulse = Vector(0, 0, 0);
	Impulse.setCoordinates(contactNormal.getCoordinates() * impulse_mag);

	Vector V_a = Vector(0, 0, 0);
	V_a.setCoordinates( Impulse.getCoordinates() * ((float)1 / particles[0]->mass) );
	particles[0]->getVelocity()->setCoordinates(particles[0]->getVelocity()->getCoordinates() + V_a.getCoordinates());
	
	if (particles[1]) {
		Vector V_b = Vector(0, 0, 0);
		particles[1]->getVelocity()->setCoordinates(particles[1]->getVelocity()->getCoordinates() + V_b.getCoordinates());

	}
}

void ParticleContact::Resolve(float time) {
	this->ResolveVelocity(time);
}