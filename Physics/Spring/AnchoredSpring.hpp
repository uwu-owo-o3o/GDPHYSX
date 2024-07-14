#pragma once

#include "../Generator/ForceGenerator.hpp"

namespace component {
	using namespace generator;
	class AnchoredSpring : public ForceGenerator{
		public:
			Vector anchorPoint;
			float springConstant;
			float restLength;
		
		public:
			AnchoredSpring(Vector pos, float springconstant, float restlength);
			void UpdateForce(Particle* particle, float time) override;
	};
}