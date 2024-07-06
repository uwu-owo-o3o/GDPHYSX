#pragma once

#include "list"
#include "../Component/Particle/Particle.hpp"
#include "ForceGenerator.hpp"

namespace generator {
	using namespace component;
	class ForceRegistry {
		protected:
			struct ParticleForceRegistery {
				Particle* particle;
				ForceGenerator* generator;
			};
			std::list<ParticleForceRegistery> Registry;
		public:
			void Add(Particle* partice, ForceGenerator* generator);
			void Remove(Particle* particle, ForceGenerator* generator);
			void Clear();
			void UpdateForces(float time);
	};
		
}