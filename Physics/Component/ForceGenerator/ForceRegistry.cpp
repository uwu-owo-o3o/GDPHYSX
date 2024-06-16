#include "ForceRegistry.hpp"

using namespace component;

void ForceRegistry::Add(Particle* particle, ForceGenerator* generator) {

	ParticleForRegistry	toAdd;
	toAdd.particle = particle;
	toAdd.generator = generator;

	Registry.push_back(toAdd);
}

void ForceRegistry::Remove(Particle* particle, ForceGenerator* generator) {
	Registry.remove_if(
		[particle, generator](ParticleForRegistry reg) {
			return reg.particle == particle && reg.generator == generator;
		}
	)
}

void ForceRegistry::Clear() {
	Registry.clear();
}

void ForceRegistry::UpdateForces(float time) {
	
}