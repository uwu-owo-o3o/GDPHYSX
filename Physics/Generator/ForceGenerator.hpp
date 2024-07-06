#pragma once

#include "../Component/Particle/Particle.hpp"

namespace generator {
	using namespace component;
	class ForceGenerator {
		public:
			virtual void UpdateForce(Particle* partice, float time);
	};
}
