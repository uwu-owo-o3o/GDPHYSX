#include "CableCreator.hpp"

CableCreator::CableCreator() {
	this->particleRadius = 5.0f;	
	this->circleDiameter = 80.0f;
	this->cableLength = 15.0f;
}
CableSet CableCreator::createCables() {

	CableSet cableSet; 

	int total_spheres = 8;
	float angle = 360.0f / total_spheres;

	for (int i = 0; i < total_spheres; i++) {
		
		Particle* particle = new Particle();
		particle->mass = 60.0f;
		particle->radius = this->particleRadius;
		particle->lifeSpan = 100.0f;

		float angle_split = ( 3.14 * angle * i) / 180.0f;
		float x = ( (this->circleDiameter / 2) * cos(angle_split) );
		float z = ( (this->circleDiameter / 2) * sin(angle_split) );
		float y = 0;

		particle->setPosition(Vector3(x, y, z));
		this->angles.push_back(angle_split);

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

void CableCreator::rotateCables(CableSet* cableSet, float deltaTime) {
		
	for (int i = 0; i < cableSet->cables.size(); i++) {


		this->angles[i] += this->rotate_multiplier * deltaTime;

		float x = ((this->circleDiameter / 2) * cos(this->angles[i]));
		float z = ((this->circleDiameter / 2) * sin(this->angles[i]));
		float y = cableSet->cables[i]->particles[1]->position.y;

		cableSet->cables[i]->particles[1]->position = Vector3(x, y, z);

		cableSet->cables[i]->particles[0]->position = Vector3(cableSet->cables[i]->particles[1]->position.x, 
															  cableSet->cables[i]->particles[0]->position.y, 
															  cableSet->cables[i]->particles[1]->position.z);				
	}

}

void CableCreator::increaseCableLength(CableSet* cableSet) {
	for (int i = 0; i < cableSet->cables.size(); i++) {
		cableSet->cables[i]->cableLength++;
	}
}

void CableCreator::decreaseCableLength(CableSet* cableSet) {
	for (int i = 0; i < cableSet->cables.size(); i++) {
		if (cableSet->cables[i]->cableLength > 0) {
			cableSet->cables[i]->cableLength--;
		}
		
	}
}

void CableCreator::increaseRotateMultiplier() {
	this->rotate_multiplier++;
}

void CableCreator::decreaseRotateMultiplier() {
	if (rotate_multiplier > 0) {
		this->rotate_multiplier--;
	}

	
	//std::cout << "rotate multiplier: " << rotate_multiplier << std::endl;
}


