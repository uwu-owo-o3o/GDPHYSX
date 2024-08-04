#include "CableCreator.hpp"

CableCreator::CableCreator() {
	this->particleRadius = 5.0f;	
	this->circleDiameter = 80.0f;
	this->cableLength = 15.0f;
}
CableSet CableCreator::createCables() {

	CableSet cableSet; 
	int total_spheres = 8;

	for (int i = 0; i < total_spheres; i++) {
		
		Particle* particle = new Particle();
		particle->mass = 60.0f;
		particle->radius = this->particleRadius;
		particle->lifeSpan = 100.0f;

		float angle_split = ( 3.14 * 45.0f * i) / 180.0f;
		float x = ( (this->circleDiameter / 2) * cos(angle_split) );
		float z = ( (this->circleDiameter / 2) * sin(angle_split) );
		float y = 0;

		particle->setPosition(Vector3(x, y, z));

		Cable* cable = new Cable(particle->position + Vector3::up * 0.0f, particle, cableLength);
		cableSet.particles.push_back(particle);
		cableSet.cables.push_back(cable);

	}
	
	return cableSet;
}

void CableCreator::raiseCables(CableSet* cableSet) {
	for (int i = 0; i < cableSet->cables.size(); i++) {
		while (cableSet->cables[i]->anchorPosition.y < 40) {
			cableSet->cables[i]->anchorPosition.y += 1.0f;
		}
	}

	/*for (int i = 0; i < cableSet->cables.size(); i++) {
		std::cout << "i: " << i << " anchorPos y: " << cableSet->cables[i]->anchorPosition.y << std::endl;
	}*/

}

