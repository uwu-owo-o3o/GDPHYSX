#include "DragForceGenerator.hpp"

using namespace generator;

DragForceGenerator::DragForceGenerator() {

}

DragForceGenerator::DragForceGenerator(float _k1, float _k2) : k1(_k1), k2(_k2) {

}

void DragForceGenerator::UpdateForce(Particle* particle, float time) {
	Vector force = Vector(0, 0, 0);	
	Vector currV = *particle->getVelocity();

	currV.calculateMagnitude();
	float mag = currV.getMagnitude();

	if (mag <= 0) {
		return;
	}

	float dragF = (k1 * mag) + (k2 * mag);
	currV.calculateDirection();
	Vector dir = Vector(0, 0, 0);
	dir.setCoordinates(currV.getDirection());

	force.setCoordinates(dir.getCoordinates() * - dragF);
	particle->AddForce(force);
}