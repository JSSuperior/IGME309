// Course: IGME 309
// Student Name: Theo Ruefli
// Assignment 04

#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>

using namespace glm;
using namespace std;

class SquareObject
{
private:
	vector <vec2> vertices;
	float xLoc, yLoc;
	float rotation;
	vec3 color;
public:
	SquareObject(float x, float y, float width, float height, float startingRot);
	~SquareObject();
	void draw();
	void rotate(float degrees);
	void changeColor(vec3 newColor);
};

