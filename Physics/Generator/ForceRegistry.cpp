#include "ForceRegistry.hpp"

using namespace generator;

void ForceRegistry::Add(Particle* particle, ForceGenerator* generator) {
	ParticleForceRegistery toAdd;
	toAdd.particle = particle;
	toAdd.generator = generator;

	Registry.push_back(toAdd);
}

void ForceRegistry::Remove(Particle* particle, ForceGenerator* generator) {
	Registry.remove_if(
		[particle, generator](ParticleForceRegistery reg) 
		{ return reg.particle == particle && reg.generator == generator;}
						);
}

void ForceRegistry::Clear() {
	Registry.clear();
}

void ForceRegistry::UpdateForces(float time) {
	for (std::list<ParticleForceRegistery>::iterator i = Registry.begin(); i != Registry.end(); i++) {
		i->generator->UpdateForce(i->particle, time);
	}
}
