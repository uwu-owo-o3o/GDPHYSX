#pragma once

#include "../Collision/ParticleContact.hpp"

namespace component {
	using namespace collision;
	class ParticleLink {
		public:
			Particle* particles[2];
			virtual ParticleContact* GetContact() { return nullptr; };
			float CurrentLength();
	};
}