#include "ParticleLink.hpp"

using namespace component;

float ParticleLink::CurrentLength() {
	Vector ret = Vector();
	ret.setCoordinates(particles[0]->getPosition()->getCoordinates() - particles[1]->getPosition()->getCoordinates());
	ret.calculateMagnitude();

	return ret.getMagnitude();
}