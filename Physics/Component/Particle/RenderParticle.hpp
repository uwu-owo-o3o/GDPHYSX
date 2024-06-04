#pragma once

#include "Particle.hpp"
#include "../../../Model3D/Model3D.hpp"
#include "../Vector.hpp"
namespace component {
	using namespace model;
	class RenderParticle {
		public:
			Particle* pReferenceParticle;
			Model3D* pReferenceModel;
			Vector CColor;
		public:
			RenderParticle(Particle* pParticle, Model3D* pModel3D, Vector Color);
			void Draw();
	};
}