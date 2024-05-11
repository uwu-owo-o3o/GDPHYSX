#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../tiny_obj_loader.h"

namespace data {
	class ObjData {
		private:
			bool bInitialized;
		private:
			std::vector<tinyobj::shape_t> vecShapes;
			std::vector<tinyobj::material_t> vecMaterial;
			tinyobj::attrib_t atAttributes;
			std::vector<GLfloat> vecFullVertexData;

		public:
			ObjData(std::string strPath);
		private:
			void initializeModelData(std::string strPath);

		public:
			bool getInitialized();
			std::vector<tinyobj::shape_t> getShapes();
			std::vector<tinyobj::material_t> getMaterial();
			tinyobj::attrib_t getAttributes();
			std::vector<GLfloat> getFullVertexData();
	};
}