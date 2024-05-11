#define TINYOBJLOADER_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "MainScene/MainScene.hpp"

using namespace scene;

int main() {
	MainScene CMainScene = MainScene();
	CMainScene.run();
	return 0;
}