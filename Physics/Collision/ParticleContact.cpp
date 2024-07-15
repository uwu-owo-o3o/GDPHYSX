#include "ParticleContact.hpp"

using namespace collision;

float ParticleContact::GetSeparatingSpeed() {
	Vector velocity = Vector();
	velocity.setCoordinates(particles[0]->getVelocity()->getCoordinates());
		
	//std::cout << "name: " << particles[0]->name << std::endl;
	//std::cout << velocity.getCoordinates().x << std::endl;

	if (particles[1]) {

		//std::cout << "name: " << particles[1]->name << std::endl;
		//std::cout << particles[1]->getVelocity()->getCoordinates().x << std::endl;

		glm::vec3 vel = velocity.subtract(*particles[1]->getVelocity());
		velocity.setCoordinates(vel);
		
	}

	return velocity.calculateScalarProduct(contactNormal);
}

void ParticleContact::ResolveVelocity(float time) {
	float separatingSpeed = this->GetSeparatingSpeed();

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
	Vector Impulse = Vector();
	Impulse.setCoordinates(contactNormal.getCoordinates() * impulse_mag);
	//std::cout << "Impulse x: " << Impulse.getCoordinates().x << std::endl;
		
	Vector V_a = Vector();
	V_a.setCoordinates( Impulse.getCoordinates() * ((float)1 / particles[0]->mass) );
	particles[0]->getVelocity()->setCoordinates(particles[0]->getVelocity()->getCoordinates() + V_a.getCoordinates());
	
	if (particles[1]) {
		Vector V_b = Vector();
		V_b.setCoordinates(Impulse.getCoordinates() * ((float)-1 / particles[1]->mass));
		particles[1]->getVelocity()->setCoordinates(particles[1]->getVelocity()->getCoordinates() + V_b.getCoordinates());

	}
}

void ParticleContact::Resolve(float time) {
	this->ResolveVelocity(time);
	this->ResolveInterpenetration(time);
	
}

void ParticleContact::ResolveInterpenetration(float time) {
	if (depth <= 0) {
		return;
	}	

	float totalMass = (float)1 / particles[0]->mass;
	if (particles[1]) {
		totalMass += (float)1 / particles[1]->mass;
	}

	if (totalMass <= 0) {
		return;
	}

	float totalMoveByMass = depth / totalMass;
	Vector moveByMass = Vector();
	moveByMass.setCoordinates(contactNormal.scalarMultiply(totalMoveByMass));

	Vector P_a = Vector();
	P_a.setCoordinates(moveByMass.getCoordinates() * ((float)1/particles[0]->mass));
	
	glm::vec3 pos1 = particles[0]->getPosition()->add(P_a);
	particles[0]->getPosition()->setCoordinates(pos1);

	if (particles[1]) {
		Vector P_b = Vector();
		P_b.setCoordinates(moveByMass.getCoordinates() * (-(float)1 / particles[1]->mass));

		glm::vec3 pos2 = particles[1]->getPosition()->add(P_b);
		particles[1]->getPosition()->setCoordinates(pos2);
	
	}

	depth = 0;
}