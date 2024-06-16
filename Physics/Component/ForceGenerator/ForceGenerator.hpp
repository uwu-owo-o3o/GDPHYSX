#pragma once

#include "../Particle/Particle.hpp"

namespace component {
	class ForceGenerator {
		public:
			virtual void UpdateForce(Particle* particle, float time);
	};
}