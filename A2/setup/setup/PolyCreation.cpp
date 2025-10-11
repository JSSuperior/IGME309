// Course: IGME 309
// Student Name: Theo Ruelfi
// Assignment: 02

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include "PolyObject.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>

// the window's width and height
float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 600, 600 };

vec2 mousePos(0,0);     // mouse canvas positon

vector <PolyObject> completedPolygons;  // vector of completed polygons
PolyObject currentPolygon;              // current polygon being created
vec3 polygonColor = vec3(0,0,0);        // color of current and future polygons

void init(void)
{
    currentPolygon = PolyObject();
    currentPolygon.setColor(polygonColor);
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(2.0f);
    glLineWidth(2.0f);

    // draw previously created polygons
    for (unsigned int i = 0; i < completedPolygons.size(); i++)
    {
        completedPolygons[i].draw();
    }

    // draw polygon currently being created
    currentPolygon.setColor(polygonColor);
    currentPolygon.draw(mousePos);    

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    rasterSize[0] = w;
    rasterSize[1] = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
    glViewport(0, 0, rasterSize[0], rasterSize[1]);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    // add a polygon to completed polygon vector
    if (key == 'A' || key == 'a')
    {
        completedPolygons.push_back(currentPolygon);
        currentPolygon = PolyObject();
    }
}

void mousePress(int button, int state, int x, int y)
{
    // add a vertex to polygon currently being created
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        currentPolygon.addVertex(vec2(mousePos.x, mousePos.y));
    }
}

void mouseMotion(int mouseX, int mouseY)
{
    // update mouse position on canvas
    mousePos.x = (float)mouseX / rasterSize[0] * canvasSize[0];
    mousePos.y = (float)(rasterSize[1] - mouseY) / rasterSize[1] * canvasSize[1];

    glutPostRedisplay();
}

void mainMenu(int value)
{
    // clear screen and quit program
    switch (value)
    {
    case 1:
        completedPolygons.clear();
        currentPolygon = PolyObject();
        break;
    case 2:
        exit(0);
        break;
    }

    glutPostRedisplay();
}

void colorMenu(int value)
{
    // update current and future polygon color
    switch (value)
    {
    case 1:
        polygonColor = vec3(255, 0, 0);
        break;
    case 2:
        polygonColor = vec3(0, 255, 0);
        break;
    case 3:
        polygonColor = vec3(0, 0, 255);
        break;
    case 4:
        polygonColor = vec3(0, 0, 0);
    }

    glutPostRedisplay();
}

void createMenu()
{
    // color menu creation
    int color = glutCreateMenu(colorMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Black", 4);

    // main menu creation
    int main = glutCreateMenu(mainMenu);
    glutAddSubMenu("Color", color);
    glutAddMenuEntry("Clear", 1);
    glutAddMenuEntry("Quit", 2);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Polygon Tool");

    // register callbacks
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(mouseMotion);
    glutMouseFunc(mousePress);
    glutKeyboardFunc(keyboard);

    // create menus
    createMenu();

    // start the glut main loop
    glutMainLoop();

    return 0;
}
