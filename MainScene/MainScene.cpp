#include "MainScene.hpp"

using namespace scene;

MainScene::MainScene() : COrthoCam(), CParticle() {
	this->intialize();
}

void MainScene::run() {
	
	constexpr std::chrono::nanoseconds time_step(16ms);
	using clock = std::chrono::high_resolution_clock;
	auto curr_time = clock::now();
	auto prev_time = curr_time;
	std::chrono::nanoseconds curr_ns(0);
	
	this->CParticle.setPosition(Vector(-250.0f, 290.0f, 0.0f));
	this->CParticle.mass = 1.0f;

	this->CParticle.AddForce(Vector(3000, 0, 0));
	
	this->CWorld.AddParticle(&this->CParticle);
	
	RenderParticle Render1 = RenderParticle(&this->CParticle, this->vecModels[0], Vector(1.0f, 0.0f, 0.0f));
	this->lRenderParticles.push_back(&Render1);

	DragForceGenerator dragForceGenerator = DragForceGenerator(0.14, 0.1);
	CWorld.forceRegistry.Add(&this->CParticle, &dragForceGenerator);

	bool bEndSim = false;
	float ticks = 0.0f;

	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ticks += 0.0001f;
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
		}

		//std::cout << "Normal Update" << std::endl;
		this->update();
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
}

void MainScene::update() {
	this->vecModels[0]->getTransform()->calculateTransformMatrix();
}

void MainScene::render() {
	
	for (std::list<RenderParticle*>::iterator i = this->lRenderParticles.begin(); i != this->lRenderParticles.end(); i++) {
		(*i)->Draw();
	}

	this->COrthoCam.draw("Sphere");

}
