#include "PhysicsWorld.hpp"

using namespace world;

void PhysicsWorld::AddParticle(Particle* toAdd) {
	this->Particles.push_back(toAdd);
}

void PhysicsWorld::Update(float time) {
	UpdateParticleList();
	for (std::list<Particle*>::iterator p = Particles.begin(); p != Particles.end(); p++) {
		
		(*p)->Update(time);
		
	}
}

void PhysicsWorld::UpdateParticleList() {
	Particles.remove_if(
		[](Particle* p) {
			return p->checkIfDestroyed();
		}
	);
}

