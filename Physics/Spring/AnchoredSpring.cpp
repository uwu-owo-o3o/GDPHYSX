#include "AnchoredSpring.hpp"

using namespace component;

AnchoredSpring::AnchoredSpring(Vector pos, float springconstant, float restlength) : anchorPoint(pos) {
	this->springConstant = springconstant;
	this->restLength = restlength;
}

void AnchoredSpring::UpdateForce(Particle* particle, float time) {
	Vector pos = *particle->getPosition();
	Vector force = Vector();
	force.setCoordinates(particle->getPosition()->getCoordinates() - anchorPoint.getCoordinates());

	force.calculateMagnitude();
	float mag = force.getMagnitude();

	float springForce = -springConstant * abs(mag - restLength);

	force.calculateDirection();
	force.setCoordinates(force.getDirection());

	force.setCoordinates(force.getCoordinates() * springForce);

	particle->AddForce(force);

}