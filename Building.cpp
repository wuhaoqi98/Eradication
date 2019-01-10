#include "Building.h"
#include "Window.h"

vector<char*> buildingTextures
{
	"../building.jpg",
	"../building2.jpg",
	"../building3.jpg",
	"../building4.jpg",
	"../building5.jpg",
	"../back.jpg"
};

Building::Building(int type, int height, float size, glm::vec3 pos)
{
	this->type = type;
	this->height = height;
	this->size = size;
	transform = pos;
	isVisible = true;
	for (int i = 0; i < height; i++) {
		BuildingCube* bc = new BuildingCube(pos, buildingTextures[type], type);
		pos.y += size * 2.0f;
		cubes.push_back(bc);
	}
}

Building::~Building()
{
	for (int i = 0; i < height; i++) {
		delete(cubes[i]);
	}
}

void Building::draw(GLuint shaderProgram)
{ 
	if (isVisible) {
		for (int i = 0; i < height; i++) {
			cubes[i]->draw(shaderProgram);
		}
	}
}

void Building::update()
{
	for (int i = 0; i < height; i++) {
		cubes[i]->update();
	}
}

void Building::translate(glm::vec3 t)
{
	for (BuildingCube* bc : cubes) {
		bc->toWorld = glm::translate(bc->toWorld, t);
	}
	transform += t;
}

