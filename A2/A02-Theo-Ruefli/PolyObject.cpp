// Course: IGME 309
// Student Name: Theo Ruelfi
// Assignment: 02

#include "PolyObject.h"
#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

PolyObject::PolyObject()
{
}

PolyObject::~PolyObject()
{
}

void PolyObject::addVertex(vec2 p_vert)
{
	vertices.push_back(p_vert);
}

void PolyObject::setColor(vec3 p_color)
{
	color = p_color;
}

unsigned int PolyObject::getVertNum()
{
	return vertices.size();
}

void PolyObject::draw()
{
	unsigned int vertNum = getVertNum();

	glColor3f(color.x, color.y, color.z);

	switch (vertNum)
	{
	case 1:
		glBegin(GL_POINTS);
		break;
	case 2:
		glBegin(GL_LINES);
		break;
	default:
		glBegin(GL_POLYGON);
		break;
	}

	for (unsigned int i = 0; i < vertNum; i++)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}

	glEnd();
}

void PolyObject::draw(vec2 p_mousePos)
{
	unsigned int vertNum = getVertNum();

	glColor3f(color.x, color.y, color.z);

	switch (vertNum)
	{
	case 1:
		glBegin(GL_LINES);
		break;
	default:
		glBegin(GL_POLYGON);
		break;
	}

	for (unsigned int i = 0; i < vertNum; i++) 
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}

	glVertex2f(p_mousePos.x, p_mousePos.y);

	glEnd();
}
