#pragma once

#include "../Component/Particle/Particle.hpp"

namespace collision {
	using namespace component;
	class ParticleContact {
		public:
			Particle* particles[2];
			float restitution;
			Vector contactNormal;
		public:
			void Resolve(float time);
		public:
			float GetSeparatingSpeed();
			void ResolveVelocity(float time);

	};
}