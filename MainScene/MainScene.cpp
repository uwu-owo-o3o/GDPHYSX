#include "MainScene.hpp"

using namespace scene;

MainScene::MainScene() : COrthoCam(), CTopLeftParticle(), CSimController(), CBottomRightParticle(), CTopRightParticle(), CBottomLeftParticle() {
	this->intialize();
}

void MainScene::run() {
	
	constexpr std::chrono::nanoseconds time_step(16ms);
	using clock = std::chrono::high_resolution_clock;
	auto curr_time = clock::now();
	auto prev_time = curr_time;
	std::chrono::nanoseconds curr_ns(0);
	
	this->CTopLeftParticle.setPosition(Vector(-300.0f, 300.0f, 201.0f));
	
	glm::vec3 velocity = this->CSimController.deriveVelocity(&this->CTopLeftParticle, 80.0f);
	this->CTopLeftParticle.setVelocity(Vector(velocity.x, velocity.y, velocity.z));
	glm::vec3 acceleration = this->CSimController.deriveVelocity(&this->CTopLeftParticle, 14.5);
	this->CTopLeftParticle.setAcceleration(Vector(acceleration.x, acceleration.y, acceleration.z));
	
	this->CBottomRightParticle.setPosition(Vector(300.0f, -300.0f, -300.0f));

	glm::vec3 velocity2 = this->CSimController.deriveVelocity(&this->CBottomRightParticle, 130.0f);
	this->CBottomRightParticle.setVelocity(Vector(velocity2.x, velocity2.y, velocity2.z));
	glm::vec3 acceleration2 = this->CSimController.deriveVelocity(&this->CBottomRightParticle, 1.0f);
	this->CBottomRightParticle.setAcceleration(Vector(acceleration2.x, acceleration2.y, acceleration2.z));

	this->CTopRightParticle.setPosition(Vector(300.0f, 300.0f, 173.0f));

	glm::vec3 velocity3 = this->CSimController.deriveVelocity(&this->CTopRightParticle, 90.0f);
	this->CTopRightParticle.setVelocity(Vector(velocity3.x, velocity3.y, velocity3.z));
	glm::vec3 acceleration3 = this->CSimController.deriveVelocity(&this->CTopRightParticle, 8.0f);
	this->CTopRightParticle.setAcceleration(Vector(acceleration3.x, acceleration3.y, acceleration3.z));

	this->CBottomLeftParticle.setPosition(Vector(-300.0f, -300.0f, -150.0f));

	glm::vec3 velocity4 = this->CSimController.deriveVelocity(&this->CBottomLeftParticle, 110.0f);
	this->CBottomLeftParticle.setVelocity(Vector(velocity4.x, velocity4.y, velocity4.z));
	glm::vec3 acceleration4 = this->CSimController.deriveVelocity(&this->CBottomLeftParticle, 3.0f);
	this->CBottomLeftParticle.setAcceleration(Vector(acceleration4.x, acceleration4.y, acceleration4.z));

	this->CWorld.AddParticle(&this->CTopLeftParticle);
	this->CWorld.AddParticle(&this->CBottomRightParticle);
	this->CWorld.AddParticle(&this->CTopRightParticle);
	this->CWorld.AddParticle(&this->CBottomLeftParticle);

	RenderParticle Render1 = RenderParticle(&this->CTopLeftParticle, this->vecModels[0], Vector(1.0f, 0.0f, 0.0f));
	this->lRenderParticles.push_back(&Render1);

	RenderParticle Render2 = RenderParticle(&this->CBottomRightParticle, this->vecModels[1], Vector(0.0f, 1.0f, 0.0f));
	this->lRenderParticles.push_back(&Render2);

	RenderParticle Render3 = RenderParticle(&this->CTopRightParticle, this->vecModels[2], Vector(0.0f, .0f, 1.0f));
	this->lRenderParticles.push_back(&Render3);

	RenderParticle Render4 = RenderParticle(&this->CBottomLeftParticle, this->vecModels[3], Vector(1.0f, 1.0f, 0.0f));
	this->lRenderParticles.push_back(&Render4);

	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		curr_time = clock::now();
		auto durr = std::chrono::duration_cast<std::chrono::nanoseconds>(curr_time - prev_time);
		prev_time = curr_time;
		curr_ns += durr;

		if (curr_ns >= time_step) {
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_ns);
			//std::cout << "MS: " << (float)ms.count() << "\n";
			curr_ns -= curr_ns;
			//std::cout << "P6 Update" << std::endl;
			this->CWorld.Update((float)ms.count() / 1000);
			//this->CParticle.Update((float)ms.count() / 1000);
			//this->CSimController.invertVelocity(&this->CParticle, (float)ms.count() / 1000);

		}

		
		
		//std::cout << "Normal Update" << std::endl;
		this->update();
		//this->vecModels[0]->getTransform()->setAtt(TransformAtt::TRANSLATE, this->CTopLeftParticle.getPosition()->getCoordinates());
		this->render();

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
	pSphere->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(20.0f, 20.0f, 20.0f));
	this->vecModels.push_back(pSphere);

	Model3D* pSphere2 = new Model3D("3D/sphere.obj");
	pSphere2->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere2->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(20.0f, 20.0f, 20.0f));
	this->vecModels.push_back(pSphere2);
	
	Model3D* pSphere3 = new Model3D("3D/sphere.obj");
	pSphere3->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere3->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(20.0f, 20.0f, 20.0f));
	this->vecModels.push_back(pSphere3);

	Model3D* pSphere4 = new Model3D("3D/sphere.obj");
	pSphere4->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	pSphere4->getTransform()->setAtt(TransformAtt::SCALE, glm::vec3(20.0f, 20.0f, 20.0f));
	this->vecModels.push_back(pSphere4);

}

void MainScene::update() {
	this->vecModels[0]->getTransform()->calculateTransformMatrix();
	this->vecModels[1]->getTransform()->calculateTransformMatrix();
	this->vecModels[2]->getTransform()->calculateTransformMatrix();
	this->vecModels[3]->getTransform()->calculateTransformMatrix();

}

void MainScene::render() {
	
	for (std::list<RenderParticle*>::iterator i = this->lRenderParticles.begin(); i != this->lRenderParticles.end(); i++) {
		(*i)->Draw();
	}

	this->COrthoCam.draw("Sphere");

}
