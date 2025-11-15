// Course: IGME 309
// Student Name: Theo Ruefli
// Assignment 04

#include "SquareObject.h"
#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

SquareObject::SquareObject(float x, float y, float width, float height, float startingRot)
{
	// draws from top left => top right => bottom right => bottom left
	vertices.push_back(vec2(x-(width/2), y));
	vertices.push_back(vec2(x+(width/2), y));
	vertices.push_back(vec2(x+(width/2), y-height));
	vertices.push_back(vec2(x-(width/2), y-height));

	xLoc = x;
	yLoc = y;
	rotation = startingRot;
	color = vec3(0,0,0);
}

SquareObject::~SquareObject()
{
}

void SquareObject::draw()
{
	glTranslatef(xLoc, yLoc, 0.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	glTranslatef(-xLoc, -yLoc, 0.0f);

	glColor3f(color.x, color.y, color.z);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < vertices.size(); i++)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
}

void SquareObject::rotate(float degrees)
{
	rotation += degrees;
}

void SquareObject::changeColor(vec3 newColor)
{
	color = newColor;
}
