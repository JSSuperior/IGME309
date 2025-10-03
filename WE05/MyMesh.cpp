// Course:			IGME 309
// Student Name:	Theo Ruefli
// Friday Exercise:	05

#include "MyMesh.h"
#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
using namespace std;

MyMesh::MyMesh()
{
	vertNum = triNum = 0;
	vertices = NULL;
	indices = NULL;
	vertColors = NULL;
}

MyMesh::~MyMesh()
{
	if (vertices != NULL)
		delete[] vertices; 
	if (indices != NULL)
		delete[] indices;

	if (vertColors != NULL)
		delete[] vertColors;
}

void MyMesh::load(char* fileName)
{
	vertNum = 0;
	triNum = 0;

	vertices = new float[100 * 2];
	indices = new unsigned int[100 * 3];
	vertColors = new float[100 * 3];

	ifstream file(fileName);

	if (!file.is_open()) {
		// Handle error
		throw runtime_error("File failed to open");
	}

	/****************************************/
	// Write your code below

	// Grab each line 
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string prefix;
		ss >> prefix;

		//cout << prefix;

		// Check the prefix, if vertex add to vertices array, otherwise add to indicies array
		if (prefix == "v")
		{
			string x, y;

			ss >> x >> y;

			vertNum++;

			vertices[(vertNum * 2) + 0] = stof(x);
			vertices[(vertNum * 2) + 1] = stof(y);
		    //cout << vertices[(vertNum * 2) + 0] << vertices[(vertNum * 2) + 1] << endl;
		}
		else if (prefix == "f")
		{
			string x, y, z;

			ss >> x >> y >> z;

			indices[(triNum * 3) + 0] = stoi(x);
			indices[(triNum * 3) + 1] = stoi(y);
			indices[(triNum * 3) + 2] = stoi(z);

			triNum++;
		}
	}
	
	if (file.is_open())
	{
		file.close();
	}

	// Write your code above
	/****************************************/

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++) {
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}
}

void MyMesh::load(const unsigned int p_vertNum, const unsigned int p_triNum, const float* p_vertices, const unsigned int* p_indices)
{
	vertNum = p_vertNum;
	triNum = p_triNum;

	vertices = new float[vertNum*2];
	indices = new unsigned int[triNum*3];
	vertColors = new float[vertNum * 3]; 

	for (unsigned int i = 0; i < vertNum*2; i++) {
		vertices[i] = p_vertices[i];
	}

	for (unsigned int i = 0; i < triNum * 3; i++) {
		indices[i] = p_indices[i];
	}

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++) {
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1); 
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}

}

void MyMesh::update()
{
	// we will use this for transformations later.... 
}

void MyMesh::draw()
{
	for (int i = 0; i < triNum; ++i) {
		glBegin(GL_TRIANGLES);
		glColor3fv(vertColors + indices[i * 3 + 0] * 3);
		glVertex2fv(vertices + indices[i * 3 + 0] * 2);

		glColor3fv(vertColors + indices[i * 3 + 1] * 3);
		glVertex2fv(vertices + indices[i * 3 + 1] * 2);

		glColor3fv(vertColors + indices[i * 3 + 2] * 3);
		glVertex2fv(vertices + indices[i * 3 + 2] * 2);
		glEnd();
	}
}