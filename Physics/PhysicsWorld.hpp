#pragma once

#include "list"
#include "Component/Particle/Particle.hpp"
#include "Generator/ForceRegistry.hpp"
#include "Generator/GravityForceGenerator.hpp"

namespace world {
	using namespace generator;
	using namespace component;
	class PhysicsWorld {
		public:
			ForceRegistry forceRegistry;
			GravityForceGenerator Gravity = GravityForceGenerator(Vector(0.0f, 0.0f, 0.0f));
			std::list<Particle*> Particles;
		public:
			void AddParticle(Particle* toAdd);
			void Update(float time);
		public:
			void UpdateParticleList();
	};
}