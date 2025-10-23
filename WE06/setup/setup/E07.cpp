// Course: IGME 309
// Student Name: Theo Ruefli
// Weekly Exercise: 07

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <ctime>
#include <cmath>

using namespace std;

float canvasSize[] = { 20.0f, 20.0f };
int rasterSize[] = { 600, 600 };

// tracking the game time - millisecond 
unsigned int curTime = 0;
unsigned int preTime = 0;
float deltaTime = 0;

float rotationAngle = 0.0f;
float rotateSpeed = 90.0f;
int vertNum = 30;
float radius = 1.0f;


void display(void)
{
	glClearColor(0.9f, 0.9f, 0.7f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*****************************/
	// write your code below

	glColor3f(0,0,0);
	glLineWidth(2.0f);
	glPointSize(10.0f);

	glTranslatef(10,10,0);
	glRotatef(rotationAngle, 0, 0, 1);
	glTranslatef(-10,-10,0);
	glBegin(GL_LINES);
	glVertex2f(10,10);
	glVertex2f(10,5);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2f(10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertNum; ++i) {
		float t = (float)i / vertNum * 2.0f * 3.14f;
		glVertex2f(10 + radius * cos(t), 5 + radius * sin(t));
	}
	glEnd();

	// origin 10.0f, 10.0f
	// lowerpoint 10.0f, 5.0f

	// so translate coordinate system origin to point of rotation (10,10)
	// rotate the coordinate system around origin by rotation angle
	// translate coordinate system back to 0,0 (-10, -10)

	// write your code above
	/*****************************/

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, canvasSize[0], 0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}


void update() {
	curTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)(curTime - preTime) / 1000.0f;


	if (rotationAngle > 45.0f) {
		rotateSpeed = -abs(rotateSpeed);
	}
	else if (rotationAngle < -45.0f) {
		rotateSpeed = abs(rotateSpeed);
	}
	rotationAngle += deltaTime * rotateSpeed;

	preTime = curTime;
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("Simple Pendulum");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(update);

	preTime = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
	return 0;
}