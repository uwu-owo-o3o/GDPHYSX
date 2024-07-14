#pragma once

#include "../Generator/ForceGenerator.hpp"

namespace component {
	using namespace generator;
	class ParticleSpring : public ForceGenerator {
		public:
			Particle* otherParticle;
			float springConstant;
			float restLength;

		public:
			ParticleSpring(Particle* particle, float springconstant, float restlength);
			void UpdateForce(Particle* particle, float time) override;
	};
}