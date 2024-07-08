#include "PhysicsWorld.hpp"

using namespace world;

void PhysicsWorld::AddParticle(Particle* toAdd) {
	this->Particles.push_back(toAdd);
	forceRegistry.Add(toAdd, &Gravity);
}

void PhysicsWorld::Update(float time) {
	UpdateParticleList();
	forceRegistry.UpdateForces(time);
	for (std::list<Particle*>::iterator p = Particles.begin(); p != Particles.end(); p++) {
		
		(*p)->Update(time);
		
	}

	if (Contacts.size() > 0) {
		//std::cout << "entered contacts.size > 0 if" << std::endl;
		contactResolver.ResolveContacts(Contacts, time);
	}
}

void PhysicsWorld::AddContact(Particle* p1, Particle* p2, float restitution, Vector contactNormal) {
	
	ParticleContact* toAdd = new ParticleContact();
	toAdd->particles[0] = p1;
	toAdd->particles[1] = p2;
	toAdd->restitution = restitution;
	toAdd->contactNormal = contactNormal;

	Contacts.push_back(toAdd);
}

void PhysicsWorld::UpdateParticleList() {
	Particles.remove_if(
		[](Particle* p) {
			return p->checkIfDestroyed();
		}
	);
}

