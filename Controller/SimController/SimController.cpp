#include "SimController.hpp"

using namespace controller;

SimController::SimController() {}

glm::vec3 SimController::deriveVelocity(Particle* pParticle, float fVelocityMagnitude) {

	pParticle->getPosition()->calculateMagnitude();
	pParticle->getPosition()->calculateDirection();
	glm::vec3 normalizedPosition = pParticle->getPosition()->getDirection();
	glm::vec3 velocity = glm::vec3(normalizedPosition.x * -1, normalizedPosition.y * -1, normalizedPosition.z * -1);
	return velocity;
	
}	

