#include "GravityForceGenerator.hpp"

using namespace generator;

GravityForceGenerator::GravityForceGenerator(const Vector gravity) : CGravity(gravity) {

}

void GravityForceGenerator::UpdateForce(Particle* particle, float time) {
	if (particle->mass <= 0) {
		return;
	}

	Vector force = Vector();
	glm::vec3 mForce = CGravity.getCoordinates() * particle->mass;
	force.setCoordinates(mForce);
	particle->AddForce(force);

}
