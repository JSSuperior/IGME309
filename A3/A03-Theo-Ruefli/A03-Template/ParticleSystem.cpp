// Course: IGME 309
// Student Name: Theo Ruefli
// Assignment: 03

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(int _numParticles)
{
	numParticles = _numParticles;	// Set the number of particles
	
	// Allocate memory for positions, velocities, colors, and lifetimes.
	positions = new float[numParticles * 3];
	velocities = new float[numParticles * 3];
	colors = new float[numParticles * 4];	
	lifeTimes = new float[numParticles];

	for (int i = 0; i < numParticles; i++) {
		// Initialize the life times
		lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;

		/***************************/
		// Write your code below
		// Please add initializations for other arrays as you see appropriate.
		
		// Set all initial positions to 0,0,0
		for (int j = 0; j < 3; j++) {
			positions[(i * 3) + j] = 0.0f;
		}

		// Initializing velocities
		velocities[(i * 3) + 0] = getRandomValue(minSpeedX,maxSpeedX);
		velocities[(i * 3) + 1] = getRandomValue(minSpeedY,maxSpeedY);
		velocities[(i * 3) + 2] = getRandomValue(minSpeedZ,maxSpeedZ);

		// Initializing color(s)
		colors[(i * 4) + 0] = 0.0f;
		colors[(i * 4) + 1] = 0.0f;
		colors[(i * 4) + 2] = 255.0f;
		colors[(i * 4) + 3] = 1.0f;

		// Write your code above
		/***************************/
	}
}

void ParticleSystem::update(float deltaTime)
{
	//std::cout << deltaTime << std::endl;

	for (int i = 0; i < numParticles; i++) {
		/***************************/
		// Write your code below
		// Update lifetime, velocity, position, and color.
		// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime

		// Updating particle velocities and positions
		for (int j = 0; j < 3; j++)
		{
			// I divided gravity by 3 in order to get a more volumous spew. Can remove /3 for full gravity
			velocities[(i * 3) + 1] += acceleration[1]/3 * deltaTime;
			positions[(i * 3) + j] += velocities[(i * 3) + j] * deltaTime;
		}

		// Updating current color alpha
		colors[(i * 4) + 3] -= (lifeTimes[i] / maxLifeTime) * deltaTime;

		// Updating lifetime
		lifeTimes[i] += deltaTime;

		// Reset particles if max lifetime
		if(lifeTimes[i] > maxLifeTime)
		{
			// Reset lifetime
			lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;

			// Reset position to 0,0,0
			for (int j = 0; j < 3; j++) {
				positions[(i * 3) + j] = 0.0f;
			}

			// Resetting velocities
			velocities[(i * 3) + 0] = getRandomValue(minSpeedX, maxSpeedX);
			velocities[(i * 3) + 1] = getRandomValue(minSpeedY, maxSpeedY);
			velocities[(i * 3) + 2] = getRandomValue(minSpeedZ, maxSpeedZ);

			// Resetting alpha
			colors[(i * 4) + 3] = 1.0f;
		}
		// Write your code above
		/***************************/
	}
}

void ParticleSystem::draw()
{
	/***************************/
	// Write your code below
	// Use GL_POINTS for rendering

	glPointSize(3.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < numParticles; i++) {		
		glColor4f(colors[(i * 4) + 0], colors[(i * 4) + 1], colors[(i * 4) + 2], colors[(i * 4) + 3]);
		glVertex3f(positions[(i * 3) + 0], positions[(i * 3) + 1], positions[(i * 3) + 2]);
	}
	glEnd();

	// Write your code above
	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}
