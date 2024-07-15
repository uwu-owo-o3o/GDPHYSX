#include "Rod.hpp"

using namespace component;

ParticleContact* Rod::GetContact() {
	float currLen = CurrentLength();
	if (currLen == length) {
		return nullptr;
	}

	ParticleContact* ret = new ParticleContact();
	ret->particles[0] = this->particles[0];
	ret->particles[1] = this->particles[1];

	Vector dir = Vector();
	glm::vec3 mDir = particles[1]->getPosition()->getCoordinates() - particles[0]->getPosition()->getCoordinates();
	dir.setCoordinates(mDir);
	dir.calculateMagnitude();
	dir.calculateDirection();
	dir.setCoordinates(dir.getDirection());

	if (currLen > length) {
		std::cout << "length is longer than expected" << std::endl;
		ret->contactNormal = dir;
		ret->depth = currLen - length;
	}
	else {
		std::cout << "length is NOT longer than expected" << std::endl;
		dir.setCoordinates(dir.scalarMultiply(-1));
		ret->contactNormal = dir;
		ret->depth = length - currLen;
	}

	std::cout << "dir coordinates: " << dir.getCoordinates().x << std::endl;
	ret->restitution = restitution;
	return ret;
}