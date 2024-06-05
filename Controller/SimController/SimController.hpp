#pragma once

#include "../../Physics/Component/Particle/Particle.hpp"
#include "../../Physics/Component/Particle/RenderParticle.hpp"
#include "../../Config/Settings.hpp"
#include "iomanip"
#include "iostream"
#include "windows.h"

namespace controller {
	using namespace component;
	class SimController {
		public:
			std::vector<Particle*> Particles;
			bool gotFirstPlace;
			bool gotSecondPlace;
			bool gotThirdPlace;
			bool gotFourthPlace;
		public:
			SimController();
		public:
			glm::vec3 deriveVelocity(Particle* pParticle, float fMagnitude);
			bool AtCenter(Particle* pParticle);
			void checkRank(Particle* pParticle, RenderParticle* pRenderParticle);
			void checkBall(RenderParticle* pRenderParticle, Particle* pParticle);
			bool checkIfBallRegistered(Particle* pParticle);
			void printResult();
			void printAverageVelocity(Particle* pParticle, std::string name);
	};
}

