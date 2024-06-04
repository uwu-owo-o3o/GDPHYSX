#pragma once

#include "../../Physics/Component/Particle/Particle.hpp"
#include "../../Config/Settings.hpp"
#include "iostream"
#include "windows.h"

namespace controller {
	using namespace component;
	class SimController {
		private:
			float fTopThreshold;
			float fBottomThreshold;
			float fDuration;
		public:
			bool bEndSim;
		public:
			SimController();
		private:
			bool checkHitTop(Particle* pParticle);
			bool checkHitBottom(Particle* pParticle);
		public:
			void invertVelocity(Particle* pParticle, float fTime);

	};
}

