#pragma once

#include "../Physics/PhysicsWorld.hpp"
#include "../Model3D/Model3D.hpp"
#include "../Physics/Component/Particle/RenderParticle.hpp"
#include "../Physics/Spring/AnchoredSpring.hpp"

namespace quiz {
	using namespace world;
	using namespace model;
	using namespace component;

	class Simulation {
		public:
			Simulation();
		public:
			void createBungee(PhysicsWorld* world, Model3D* refModel, std::list<RenderParticle*>* refList);
			void createChain(PhysicsWorld* world, Model3D* refModel);

	};
}