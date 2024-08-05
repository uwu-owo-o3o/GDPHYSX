#pragma once

#include "../Springs/ParticleSpring.hpp"
#include "../Link/Cable.hpp"
#include "../Particle.hpp"
#include "vector"
#include "unordered_map"

struct CableSet {
	std::vector<Particle*> particles;
	std::vector<Cable*> cables;
};


class CableCreator {

private:
	float cableLength;
	float circleDiameter;
	float particleRadius;
	float forceToPutOnPoint =  100000.0f;
	float rotate_multiplier = 1.0f;

public: 
	std::vector<float> angles;

public:	
	CableCreator();

public:
	CableSet createCables();
	void raiseCables(CableSet* cableSet);
	void rotateCables(CableSet* cableSet, float deltaTime);
	void increaseRotateMultiplier();
	void decreaseRotateMultiplier();
	void increaseCableLength(CableSet* cableSet);
	void decreaseCableLength(CableSet* cableSet);
	
};