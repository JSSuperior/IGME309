// Course: IGME 309
// Student Name: Theo Ruefli
// Assignment 04

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include "SquareObject.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>

// the window's width and height
float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 600, 600 };

// list of limbs
vector<SquareObject> limbList;
int limbListIndex = 0;

void init(void)
{
    // Waist
    limbList.push_back(SquareObject(5, 5, 2, 1.5, 180));

    // Torso
    limbList.push_back(SquareObject(5, 3.5, 3, 1.5, 0));

    // left arm
    limbList.push_back(SquareObject(3.5, 2.5, 1, 1, -90));
    limbList.push_back(SquareObject(3.5, 1.5, 1, 1, 0));
    limbList.push_back(SquareObject(3.5, 0.5, 1.5, 0.5, 0));

    // right arm
    limbList.push_back(SquareObject(6.5, 2.5, 1, 1, 90));
    limbList.push_back(SquareObject(6.5, 1.5, 1, 1, 0));
    limbList.push_back(SquareObject(6.5, 0.5, 1.5, 0.5, 0));

    // head
    limbList.push_back(SquareObject(5, 2, 0.5, 0.5, 0));
    limbList.push_back(SquareObject(5, 1.5, 1, 1, 0));

    // left leg
    limbList.push_back(SquareObject(4.25, 5, 1, 1, 180));
    limbList.push_back(SquareObject(4.25, 4, 1, 1, 0));
    limbList.push_back(SquareObject(4.25, 3, 1.5, 0.5, 0));

    // right leg
    limbList.push_back(SquareObject(5.75, 5, 1, 1, 180));
    limbList.push_back(SquareObject(5.75, 4, 1, 1, 0));
    limbList.push_back(SquareObject(5.75, 3, 1.5, 0.5, 0));

    // set starting highlight color
    limbList[0].changeColor(vec3(1,0,0));
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLineWidth(2);

    // Waist
    glPushMatrix();
    limbList[0].draw();

    // Torso
    glPushMatrix();
    limbList[1].draw();

    // left arm
    glPushMatrix();
    limbList[2].draw();
    glPushMatrix();
    limbList[3].draw();
    glPushMatrix();
    limbList[4].draw();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // right arm
    glPushMatrix();
    limbList[5].draw();
    glPushMatrix();
    limbList[6].draw();
    glPushMatrix();
    limbList[7].draw();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // head
    glPushMatrix();
    limbList[8].draw();
    glPushMatrix();
    limbList[9].draw();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

    // left leg
    glPushMatrix();
    limbList[10].draw();
    glPushMatrix();
    limbList[11].draw();
    glPushMatrix();
    limbList[12].draw();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // right leg
    glPushMatrix();
    limbList[13].draw();
    glPushMatrix();
    limbList[14].draw();
    glPushMatrix();
    limbList[15].draw();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

// called when window is first created or when window is resized
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
    // rotate object
    if (key == 'A' || key == 'a')
    {
        limbList[limbListIndex].rotate(10.0f);
    }
    else if (key == 'D' || key == 'd')
    {
        limbList[limbListIndex].rotate(-10.0f);
    }

    // Change object selected
    if (key == 'W' || key == 'w')
    {
        limbList[limbListIndex].changeColor(vec3(0,0,0));
        limbListIndex++;

        if (limbListIndex > limbList.size()-1)
        {
            limbListIndex = 0;
        }
        limbList[limbListIndex].changeColor(vec3(1, 0, 0));
    }
    else if (key == 'S' || key == 's')
    {
        limbList[limbListIndex].changeColor(vec3(0, 0, 0));
        limbListIndex--;

        if (limbListIndex < 0)
        {
            limbListIndex = limbList.size() - 1;
        }
        limbList[limbListIndex].changeColor(vec3(1, 0, 0));
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Assignment 4 Robot");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    //start the glut main loop
    glutMainLoop();
    return 0;
}
