#include "CableCreator.hpp"

CableCreator::CableCreator() {
	this->particleRadius = 55.0f;
	this->cableLength = 20.0f;
}

CableSet CableCreator::createCables() {


	CableSet cableSet; 

	for (int i = 0; i < 1; i++) {
		
		Particle* particle = new Particle();
		particle->mass = 60.0f;
		particle->lifeSpan = 100.0f;
		particle->radius = this->particleRadius;
		
		int x_offset = this->setXOffset(i);
		particle->setPosition(Vector3(x_offset, 0, 0));

		

		Cable* cable = new Cable(particle->position + Vector3::up * 100, particle, cableLength);

		cableSet.cables.push_back(cable);
		cableSet.particles.push_back(particle);

	}

	//leftMost = cableSet.particles[3];
	return cableSet;
}

int CableCreator::setXOffset(int i) {
	return 0;
}