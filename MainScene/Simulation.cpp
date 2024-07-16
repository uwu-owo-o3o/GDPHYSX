#include "Simulation.hpp"

using namespace quiz;


/* [EXPLANATION] */

/*
	1) Bungee: 
	   The first ball acts similar to a bungee as it fall down with no added force or velocity as
	   how one would jump at the start of a bungee. The ball doesn't reach the top point as well during the jump.

	2) Chain:






*/

Simulation::Simulation() {}

void Simulation::createBungee(PhysicsWorld* world, Model3D* refModel, std::list<RenderParticle*>* refList) {
	
	// Creates Ball //
	Particle* particle = new Particle();
	particle->name = "Bungee Ball";
	particle->radius = 15.0f;
	particle->mass = 80.0f;
	particle->setPosition(Vector(-120, 190, 0));
	//particle->AddForce(Vector(0.0f, -50000.0f, 0.0f));

	refModel->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(particle->radius, particle->radius, particle->radius));

	RenderParticle* Render1 = new RenderParticle(particle, refModel, Vector(0.0f, 0.0f, 1.0f));
	refList->push_back(Render1);	
	world->AddParticle(particle);

	AnchoredSpring* anchorSpring = new AnchoredSpring(Vector(-120, 200, 0), 3.0f, 5.0f);
	world->forceRegistry.Add(particle, anchorSpring);
}

void Simulation::createChain(PhysicsWorld* world, Model3D* refModel) {

}