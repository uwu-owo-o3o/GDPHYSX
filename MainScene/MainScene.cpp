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

	Simulation sim = Simulation();

	sim.createBungee(&this->CWorld, this->vecModels[0], &this->lRenderParticles);
	
	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		curr_time = clock::now();
		auto durr = std::chrono::duration_cast<std::chrono::nanoseconds>(curr_time - prev_time);
		prev_time = curr_time;
		curr_ns += durr;

		if (curr_ns >= time_step) {
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_ns);
			
			curr_ns -= curr_ns;
			
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

	if (!glfwInit()) {
		std::cout << "glfwInit has encountered an error!" << std::endl;
	}
	this->pWindow = glfwCreateWindow((int) SCREEN_WIDTH, (int) SCREEN_HEIGHT, "Quiz-Lance Jervic Ong", NULL, NULL);
	glfwMakeContextCurrent(this->pWindow);
	gladLoadGL();

	//glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

	ShaderManager::getInstance()->registerShaders();
	this->createSphere();
}

void MainScene::createSphere() {
	Model3D* pSphere = new Model3D("3D/sphere.obj");
	this->vecModels.push_back(pSphere);

	Model3D* pSphere2 = new Model3D("3D/sphere.obj");
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
