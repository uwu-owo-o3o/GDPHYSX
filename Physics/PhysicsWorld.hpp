#pragma once

#include "list"
#include "vector"
#include "Component/Particle/Particle.hpp"
#include "Generator/ForceRegistry.hpp"
#include "Generator/GravityForceGenerator.hpp"
#include "Collision/ParticleContact.hpp"
#include "Collision/ContactResolver.hpp"

namespace world {
	using namespace generator;
	using namespace component;
	using namespace collision;
	class PhysicsWorld {
		public:
			ForceRegistry forceRegistry;
			GravityForceGenerator Gravity = GravityForceGenerator(Vector(0.0f, 0.0f, 0.0f));
			std::list<Particle*> Particles;
			std::vector<ParticleContact*> Contacts;
		protected:
			ContactResolver contactResolver = ContactResolver(20);
		public:
			void AddParticle(Particle* toAdd);
			void Update(float time);
			void AddContact(Particle* p1, Particle* p2, float restitution, Vector contactNormal);
		public:
			void UpdateParticleList();
	};
}