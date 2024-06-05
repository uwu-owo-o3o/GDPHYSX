#include "SimController.hpp"

using namespace controller;

SimController::SimController() {
	this->gotFirstPlace = false;
	this->gotSecondPlace = false;
	this->gotThirdPlace = false;
	this->gotFourthPlace = false;
}

glm::vec3 SimController::deriveVelocity(Particle* pParticle, float fVelocityMagnitude) {

	pParticle->getPosition()->calculateMagnitude();
	pParticle->getPosition()->calculateDirection();
	glm::vec3 normalizedPosition = pParticle->getPosition()->getDirection();
	glm::vec3 velocity = glm::vec3(normalizedPosition.x * -1, normalizedPosition.y * -1, normalizedPosition.z * -1);
	return velocity;
	
}	

bool SimController::AtCenter(Particle* pParticle) {
	bool x_check = false;
	bool y_check = false;
	bool z_check = false;

	if (pParticle->getPosition()->getX() <= 0.5 && pParticle->getPosition()->getX() >= -0.5) {
		x_check = true;
	}

	if (pParticle->getPosition()->getY() <= 0.5 && pParticle->getPosition()->getY() >= -0.5) {
		y_check = true;
	}

	if (pParticle->getPosition()->getZ() <= 0.5 && pParticle->getPosition()->getZ() >= -0.5) {
		z_check = true;
	}

	if (x_check && y_check && z_check) {
		return true;
	}
	else {
		return false;
	}
	
}

void SimController::checkRank(Particle* pParticle, RenderParticle* pRenderParticle) {
	if (pParticle->checkIfDestroyed()) {
		if (!this->gotFirstPlace) {
			if (!this->checkIfBallRegistered(pParticle)) {
				this->checkBall(pRenderParticle, pParticle);
				this->gotFirstPlace = true;
				this->Particles.push_back(pParticle);
			}
		}
		else if (!this->gotSecondPlace) {
			if (!this->checkIfBallRegistered(pParticle)) {
				this->checkBall(pRenderParticle, pParticle);
				this->gotSecondPlace = true;
				this->Particles.push_back(pParticle);
			}

		}
		else if (!this->gotThirdPlace) {
			if (!this->checkIfBallRegistered(pParticle)) {
				this->checkBall(pRenderParticle, pParticle);
				this->gotThirdPlace = true;
				this->Particles.push_back(pParticle);
			}

		}
		else if (!this->gotFourthPlace) {
			if (!this->checkIfBallRegistered(pParticle)) {
				this->checkBall(pRenderParticle, pParticle);
				this->gotFourthPlace = true;
				this->Particles.push_back(pParticle);
			}

		}
	}
}

void SimController::checkBall(RenderParticle* pRenderParticle, Particle* pParticle) {
	if (pRenderParticle->CColor.getCoordinates() == glm::vec3(1, 0, 0)) {
		pParticle->name = "Red";
		pParticle->magnitudeVelocity = 80.0f;
	}
	else if (pRenderParticle->CColor.getCoordinates() == glm::vec3(0, 1, 0)) {
		pParticle->name = "Green";
		pParticle->magnitudeVelocity = 90.0f;

	}
	else if (pRenderParticle->CColor.getCoordinates() == glm::vec3(0, 0, 1)) {
		pParticle->name = "Blue";
		pParticle->magnitudeVelocity = 130.0f;
	}
	else if (pRenderParticle->CColor.getCoordinates() == glm::vec3(1, 1, 0)) {
		pParticle->name = "Yellow";
		pParticle->magnitudeVelocity = 110.0f;
	}

}

bool SimController::checkIfBallRegistered(Particle* pParticle) {
	for (int i = 0; i < this->Particles.size(); i++) {
		if (this->Particles[i] == pParticle) {
			return true;
		}
	}
	return false;
}

void SimController::printResult() {
	if (this->Particles.size() != 0) {

		std::cout << std::setprecision(2) << std::fixed;
		std::cout << "1st: " << this->Particles[0]->name << std::endl;
		std::cout << "Mag. of Velocity: " << this->Particles[0]->magnitudeVelocity << std::endl;
		this->printAverageVelocity(this->Particles[0], this->Particles[0]->name);
		std::cout << this->Particles[0]->time << " seconds" << std::endl;
		std::cout << std::endl;

		std::cout << "2nd: " << this->Particles[1]->name << std::endl;
		std::cout << "Mag. of Velocity: " << this->Particles[1]->magnitudeVelocity << std::endl;
		this->printAverageVelocity(this->Particles[1], this->Particles[1]->name);
		std::cout << this->Particles[1]->time << " seconds" << std::endl;
		std::cout << std::endl;

		std::cout << "3rd: " << this->Particles[2]->name << std::endl;
		std::cout << "Mag. of Velocity: " << this->Particles[2]->magnitudeVelocity << std::endl;
		this->printAverageVelocity(this->Particles[2], this->Particles[2]->name);
		std::cout << this->Particles[2]->time << " seconds" << std::endl;
		std::cout << std::endl;

		std::cout << "4th: " << this->Particles[3]->name << std::endl;
		std::cout << "Mag. of Velocity: " << this->Particles[3]->magnitudeVelocity << std::endl;
		this->printAverageVelocity(this->Particles[3], this->Particles[3]->name);
		std::cout << this->Particles[3]->time << " seconds" << std::endl;
		std::cout << std::endl;
	}
	
}

void SimController::printAverageVelocity(Particle* pParticle, std::string name) {
	float averageVelX = 0.0f;
	float averageVelY = 0.0f;
	float averageVelZ = 0.0f;
	if (name == "Red") {
		averageVelX = (pParticle->getPosition()->getX() - -300.0f) / (pParticle->time - 0);
		averageVelY = (pParticle->getPosition()->getY() - 300.0f) / (pParticle->time - 0);
		averageVelZ = (pParticle->getPosition()->getZ() - 201.0f) / (pParticle->time - 0);

	}
	else if (name == "Blue") {
		averageVelX = (pParticle->getPosition()->getX() - 300.0f) / (pParticle->time - 0);
		averageVelY = (pParticle->getPosition()->getY() - -300.0f) / (pParticle->time - 0);
		averageVelZ = (pParticle->getPosition()->getZ() - -300.0f) / (pParticle->time - 0);

	}
	else if (name == "Green") {
		averageVelX = (pParticle->getPosition()->getX() - 300.0f) / (pParticle->time - 0);
		averageVelY = (pParticle->getPosition()->getY() - 300.0f) / (pParticle->time - 0);
		averageVelZ = (pParticle->getPosition()->getZ() - 173.0f) / (pParticle->time - 0);
	}
	else if (name == "Yellow") {
		averageVelX = (pParticle->getPosition()->getX() - -300.0f) / (pParticle->time - 0);
		averageVelY = (pParticle->getPosition()->getY() - -300.0f) / (pParticle->time - 0);
		averageVelZ = (pParticle->getPosition()->getZ() - -150.0f) / (pParticle->time - 0);
	}
	std::cout << "Average Velocity: ( " << averageVelX << ", " << averageVelY << ", " << averageVelZ << " ) m/s" << std::endl;
}