#include "Rod.hpp"

using namespace component;

ParticleContact* Rod::GetContact() {
	float currLen = CurrentLength();
	if (currLen == length) {
		return nullptr;
	}

	ParticleContact* ret = new ParticleContact();
	ret->particles[0] = particles[0];
	ret->particles[1] = particles[1];

	Vector dir = Vector();
	dir.setCoordinates( particles[1]->getPosition()->getCoordinates() - particles[0]->getPosition()->getCoordinates());
	dir.calculateDirection();
	dir.setCoordinates(dir.getDirection());

	if (currLen > length) {
		ret->contactNormal = dir;
		ret->depth = currLen - length;
	}
	else {
		glm::vec3 invertedDir = dir.scalarMultiply(-1);
		ret->contactNormal.setCoordinates(invertedDir);

		ret->depth = length - currLen;
	}

	ret->restitution = restitution;
	return ret;
}