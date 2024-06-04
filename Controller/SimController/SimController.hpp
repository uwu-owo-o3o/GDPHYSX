#pragma once

#include "../../Physics/Component/Particle/Particle.hpp"
#include "../../Config/Settings.hpp"
#include "iostream"
#include "windows.h"

namespace controller {
	using namespace component;
	class SimController {
		public:
			
		public:
			SimController();
		public:
			glm::vec3 deriveVelocity(Particle* pParticle, float fMagnitude);

	};
}

