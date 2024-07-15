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

	//GenerateContacts();

	if (Contacts.size() > 0) {
		//std::cout << "entered contacts.size > 0 if" << std::endl;
		contactResolver.ResolveContacts(Contacts, time);
	}
}

void PhysicsWorld::AddContact(Particle* p1, Particle* p2, float restitution, Vector contactNormal, float depth) {
	
	ParticleContact* toAdd = new ParticleContact();
	toAdd->particles[0] = p1;
	toAdd->particles[1] = p2;
	toAdd->restitution = restitution;
	toAdd->contactNormal = contactNormal;
	toAdd->depth = depth;

	Contacts.push_back(toAdd);
}

void PhysicsWorld::UpdateParticleList() {
	Particles.remove_if(
		[](Particle* p) {
			return p->checkIfDestroyed();
		}
	);
}

void PhysicsWorld::GenerateContacts() {

	Contacts.clear();
	//GetOverlaps();

	for (std::list<ParticleLink*>::iterator i = Links.begin(); i != Links.end(); i++) {
		ParticleContact* contact = (*i)->GetContact();
		if (contact != nullptr) {
			Contacts.push_back(contact);
		}
	}
}

void PhysicsWorld::GetOverlaps() {
	for (int i = 0; i < Particles.size() - 1; i++) {
		std::list<Particle*>::iterator a = std::next(Particles.begin(), i);
		for (int h = i + 1; h < Particles.size(); h++) {
			std::list<Particle*>::iterator b = std::next(Particles.begin(), h);

			Vector mag2Vector = Vector();
			mag2Vector.setCoordinates((*a)->getPosition()->getCoordinates() - (*b)->getPosition()->getCoordinates());
			float mag2 = mag2Vector.SquareMagnitude();

			float rad = (*a)->radius + (*b)->radius;
			float rad2 = rad * rad;

			if (mag2 <= rad2) {
				mag2Vector.calculateDirection();
				Vector dir = Vector();
				dir.setCoordinates(mag2Vector.getDirection());

				float r = rad2 - mag2;
				float depth = sqrt(r);

				float restitution = fmin((*a)->restitution, (*b)->restitution);
				AddContact(*a, *b, restitution, dir, depth);
			}
		}
	}
}