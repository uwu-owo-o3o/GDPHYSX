#pragma once

#include "ForceGenerator.hpp"

namespace generator {
	class DragForceGenerator : public ForceGenerator {
		private:
			float k1 = 0.74f;
			float k2 = 0.57f;
		public:
			DragForceGenerator();
			DragForceGenerator(float _k1, float _k2);
			void UpdateForce(Particle* particle, float time) override;
	};
}