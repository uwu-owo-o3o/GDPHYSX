#include "Simulation.hpp"

using namespace quiz;

Simulation::Simulation() {}

void Simulation::createBungee(PhysicsWorld* world, Model3D* refModel, std::list<RenderParticle*>* refList) {
	Particle* particle = new Particle();
	particle->name = "Bungee Ball";
	particle->radius = 5.0f;
	particle->mass = 10.0f;
	particle->setPosition(Vector(-20, 20, 0));

	particle->AddForce(Vector(0.0f, -5000.0f, 0.0f));

	refModel->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(particle->radius, particle->radius, particle->radius));

	RenderParticle* Render1 = new RenderParticle(particle, refModel, Vector(0.0f, 0.0f, 1.0f));
	refList->push_back(Render1);	

	//AnchoredSpring anchorSpring = AnchoredSpring();

}

void Simulation::createChain(PhysicsWorld* world, Model3D* refModel) {

}