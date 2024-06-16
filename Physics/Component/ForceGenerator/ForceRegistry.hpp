#pragma once

#include "../Particle/Particle.hpp"
#include "ForceGenerator.hpp"
#include "list"

namespace component {
	class ForceRegistry {
		protected:
			struct ParticleForRegistry {
				Particle* particle;
				ForceGenerator* generator;
			};

			std::list<ParticleForRegistry> Registry;
		public:
			void Add(Particle* particle, ForceGenerator* generator);
			void Remove(Particle* particle, ForceGenerator* generator);
			void Clear();
			void UpdateForces(float time);
	};
}