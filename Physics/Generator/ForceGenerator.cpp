#include "ForceGenerator.hpp"

using namespace generator;

void ForceGenerator::UpdateForce(Particle* particle, float time) {
	particle->AddForce(Vector(0, 0, 0));
}

