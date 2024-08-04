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


public:	
	CableCreator();

public:
	CableSet createCables();
	void raiseCables(CableSet* cableSet);
	

};