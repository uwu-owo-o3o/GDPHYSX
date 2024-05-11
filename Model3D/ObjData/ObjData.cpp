#include "ObjData.hpp"

using namespace data;

ObjData::ObjData(std::string strPath) {
	this->initializeModelData(strPath);
}

void ObjData::initializeModelData(std::string strPath) {
	std::string strWarning, strError;
	this->bInitialized = tinyobj::LoadObj(&this->atAttributes, &this->vecShapes, &this->vecMaterial, &strWarning, &strError, strPath.c_str());
	
	for (int i = 0; i < this->vecShapes[0].mesh.indices.size(); i++) {
		tinyobj::index_t vData = this->vecShapes[0].mesh.indices[i];
		this->vecFullVertexData.push_back(this->atAttributes.vertices[vData.vertex_index * 3]);
		this->vecFullVertexData.push_back(this->atAttributes.vertices[vData.vertex_index * 3 + 1]);
		this->vecFullVertexData.push_back(this->atAttributes.vertices[vData.vertex_index * 3 + 2]);

		/*this->vecFullVertexData.push_back(this->atAttributes.texcoords[vData.texcoord_index * 2]);
		this->vecFullVertexData.push_back(this->atAttributes.texcoords[vData.texcoord_index * 2 + 1]);*/

	}

}

bool ObjData::getInitialized() {
	return this->bInitialized;
}

std::vector<tinyobj::shape_t>  ObjData::getShapes() {
	return this->vecShapes;
}

std::vector<tinyobj::material_t>  ObjData::getMaterial() {
	return this->vecMaterial;
}

tinyobj::attrib_t  ObjData::getAttributes() {
	return this->atAttributes;
}

std::vector<GLfloat>  ObjData::getFullVertexData() {
	return this->vecFullVertexData;
}


