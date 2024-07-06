#pragma once

#include "ForceGenerator.hpp"

namespace generator {
	class GravityForceGenerator : public ForceGenerator {
		private:
			Vector CGravity;
		public:
			GravityForceGenerator(Vector gravity);
			void UpdateForce(Particle* particle, float time) override;
	};
}