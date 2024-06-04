#pragma once

#include "../../Config/Settings.hpp"
#include "../Camera.hpp"
#include "../../Shaders/ShaderManager/ShaderManager.hpp"
#include "string"


namespace camera {
	using namespace shader;
	class OrthoCam : public Camera {
		private:
			float fLeft;
			float fRight;
			float fBottom;
			float fTop;
			float fNear;
			float fFar;

		public:
			OrthoCam();

		public:
			void draw(std::string strKey);
	};
}