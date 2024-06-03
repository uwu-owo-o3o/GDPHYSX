#pragma once

#include "list"
#include "Component/Particle/Particle.hpp"

namespace world {
	using namespace component;
	class PhysicsWorld {
		public:
			std::list<Particle*> Particles;
		public:
			void AddParticle(Particle* toAdd);
			void Update(float time);
		public:
			void UpdateParticleList();
	};
}