#include "MainScene.hpp"

using namespace scene;

MainScene::MainScene() : COrthoCam() {
	this->intialize();
}

void MainScene::run() {
	
	constexpr std::chrono::nanoseconds time_step(16ms);
	using clock = std::chrono::high_resolution_clock;
	auto curr_time = clock::now();
	auto prev_time = curr_time;
	std::chrono::nanoseconds curr_ns(0);
	
	Particle CParticle = Particle();

	CParticle.setPosition(Vector(10.0f, 0.0f, 0.0f));
	CParticle.mass = 50.0f;
	CParticle.name = "Particle 1";
	//CParticle.setVelocity(Vector(1.5f, 0.0f, 0.0f));
	//CParticle.AddForce(Vector(500000, 0, 0));
	//CParticle.setVelocity(Vector(0.6, 0.3, 0));
	this->CWorld.AddParticle(&CParticle);

	RenderParticle Render1 = RenderParticle(&CParticle, this->vecModels[0], Vector(1.0f, 0.0f, 0.0f));
	this->lRenderParticles.push_back(&Render1);

	Particle CParticle2 = Particle();
	//CParticle2.setVelocity(Vector(2.5f, 0.0f, 0.0f));
	CParticle2.setPosition(Vector(50.0f, 0.0f, 0.0f));
	CParticle2.mass = 50.0f;
	CParticle2.name = "Particle 2";
	//CParticle2.setVelocity(Vector(10, 0, 0));

	this->CWorld.AddParticle(&CParticle2);

	RenderParticle Render2 = RenderParticle(&CParticle2, this->vecModels[1], Vector(0.0f, 0.0f, 1.0f));
	this->lRenderParticles.push_back(&Render2);

	//DragForceGenerator dragForceGenerator = DragForceGenerator(0.14f, 0.1f);
	//CWorld.forceRegistry.Add(&CParticle, &dragForceGenerator);
	/*
	ParticleSpring pS = ParticleSpring(&CParticle, 5, 1);
	this->CWorld.forceRegistry.Add(&CParticle2, &pS);

	ParticleSpring pS2 = ParticleSpring(&CParticle2, 5, 1);
	this->CWorld.forceRegistry.Add(&CParticle, &pS2);*/

	//ParticleContact contact = ParticleContact();
	//contact.particles[0] = &CParticle;
	//contact.particles[1] = &CParticle2;

	//contact.contactNormal.setCoordinates(CParticle.getPosition()->getCoordinates() - CParticle2.getPosition()->getCoordinates());
	//contact.contactNormal.calculateMagnitude();
	//contact.contactNormal.calculateDirection();
	//contact.contactNormal.setCoordinates(contact.contactNormal.getDirection());
	//contact.restitution = 1;
	
	Vector dir = Vector();
	dir.setCoordinates(CParticle.getPosition()->getCoordinates() - CParticle2.getPosition()->getCoordinates());
	dir.calculateMagnitude();
	dir.calculateDirection();
	dir.setCoordinates(dir.getDirection());

	this->CWorld.AddContact(&CParticle, &CParticle2, 1, dir, 60);

	/*
	AnchoredSpring aSpring = AnchoredSpring(Vector(20, 0, 0), 5, 0.5);
	this->CWorld.forceRegistry.Add(&CParticle, &aSpring);*/

	//Rod* r = new Rod();
	//r->particles[0] = &CParticle;
	//r->particles[1] = &CParticle2;
	//r->length = 200;
	//this->CWorld.Links.push_back(r);
	
	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		curr_time = clock::now();
		auto durr = std::chrono::duration_cast<std::chrono::nanoseconds>(curr_time - prev_time);
		prev_time = curr_time;
		curr_ns += durr;
		

		//std::cout << "pre update - Particle 1 pos x: " << CParticle.getPosition()->getX() << std::endl;
		//std::cout << "pre update - Particle 1 pos y: " << CParticle.getPosition()->getY() << std::endl;
		//std::cout << "pre update - Particle 1 pos z: " << CParticle.getPosition()->getZ() << std::endl;

		if (curr_ns >= time_step) {
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_ns);
			//std::cout << "MS: " << (float)ms.count() << "\n";
			curr_ns -= curr_ns;
			//std::cout << "P6 Update" << std::endl;
			this->CWorld.Update((float)ms.count() / 1000);
			//contact.Resolve((float)ms.count() / 1000);
		}

		//std::cout << "Normal Update" << std::endl;
		this->update();
		this->render();

		//glBegin(GL_LINES);
		//	glVertex2f(aSpring.anchorPoint.getX(), aSpring.anchorPoint.getY());
		//	glVertex2f(CParticle.getPosition()->getX(), CParticle.getPosition()->getY());
		//glEnd();
		//std::cout << "post update - Particle 1 pos x: " << CParticle.getPosition()->getX() << std::endl;
		//std::cout << "post update - Particle 1 pos y: " << CParticle.getPosition()->getY() << std::endl;
		//std::cout << "post update - Particle 1 pos z: " << CParticle.getPosition()->getZ() << std::endl;

		glfwSwapBuffers(this->pWindow);
		glfwPollEvents();
	}

	glfwTerminate();
}

void MainScene::intialize() {

	//InputManager::getInstance()->askUserVelocity(&this->CParticle);
	
	if (!glfwInit()) {
		std::cout << "glfwInit has encountered an error!" << std::endl;
	}
	this->pWindow = glfwCreateWindow((int) SCREEN_WIDTH, (int) SCREEN_HEIGHT, "PC01 - Lance Jervic Ong", NULL, NULL);
	glfwMakeContextCurrent(this->pWindow);
	gladLoadGL();

	//glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

	ShaderManager::getInstance()->registerShaders();
	this->createSphere();
}

void MainScene::createSphere() {
	Model3D* pSphere = new Model3D("3D/sphere.obj");
	//pSphere->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(50.0f, 50.0f, 50.0f));
	this->vecModels.push_back(pSphere);

	Model3D* pSphere2 = new Model3D("3D/sphere.obj");
	//pSphere2->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere2->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(50.0f, 50.0f, 50.0f));
	this->vecModels.push_back(pSphere2);
}

void MainScene::update() {
	this->vecModels[0]->getTransform()->calculateTransformMatrix();
	this->vecModels[1]->getTransform()->calculateTransformMatrix();
}

void MainScene::render() {
	
	for (std::list<RenderParticle*>::iterator i = this->lRenderParticles.begin(); i != this->lRenderParticles.end(); i++) {
		(*i)->Draw();
	}

	this->COrthoCam.draw("Sphere");

}
