#pragma once

#include "../Collision/ParticleContact.hpp"
#include "ParticleLink.hpp"

namespace component {
	class Rod : public ParticleLink {

	public:
		float length = 1;
		float restitution = 0;

		ParticleContact* GetContact() override;
	};
}