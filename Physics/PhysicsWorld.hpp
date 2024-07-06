#pragma once

#include "list"
#include "Component/Particle/Particle.hpp"
#include "Component/ForceGenerator/ForceRegistry.hpp"

namespace world {
	using namespace component;
	class PhysicsWorld {
		public:
			ForceRegistry forceRegistry;
			
			std::list<Particle*> Particles;
		public:
			void AddParticle(Particle* toAdd);
			void Update(float time);
		public:
			void UpdateParticleList();
	};
}