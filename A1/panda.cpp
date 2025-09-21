// Course: IGME 309
// Student Name: Theo Ruelfi
// Assignment: 01

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include<math.h>


// the window's width and height
int width, height;

int verticies = 30;

// Modified function from pong assignment
// Draws a filled circle at location
void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius)
{
    glColor3f(red, green, blue);

    // draw the cicle
    glBegin(GL_POLYGON);
    for (int i = 0; i < verticies; ++i) {
        float t = (float)i / verticies * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(t), center_y + radius * sin(t));
    }
    glEnd();
    //glut post redisplay?
}

// Draws a wireframe circle at location
void drawWireFrameCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth)
{
    glColor3f(red, green, blue);
    glLineWidth(lineWidth);
    // draw the cicle
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < verticies; ++i) {
        float t = (float)i / verticies * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(t), center_y + radius * sin(t));
    }
    glEnd();
    //glut post redisplay?
}
void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
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

    // Belly
    drawWireFrameCircle(0.0f, 0.0f, 0.0f, 5, 3, 2.5, 20.0);

    // Head
    drawFilledCircle(0.0f, 0.0f, 0.0f, 3.5, 7.7, 0.8);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 6.5, 7.7, 0.8);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 5, 6.5, 2.0);
    drawFilledCircle(1.0f, 1.0f, 1.0f, 5, 6.5, 1.8);

    // Lefy Eye
    drawFilledCircle(0.0f, 0.0f, 0.0f, 4, 7, 0.4);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 4-0.1, 7-0.1, 0.4);
    drawFilledCircle(1.0f, 1.0f, 1.0f, 4, 7+0.1, 0.05);

    // Right Eye
    drawFilledCircle(0.0f, 0.0f, 0.0f, 6, 7, 0.4);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 6+0.1, 7-0.1, 0.4);
    drawFilledCircle(1.0f, 1.0f, 1.0f, 6, 7+0.1, 0.05);
    
    // Nose
    drawFilledCircle(0.0f, 0.0f, 0.0f, 5, 6, 0.4);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 5-0.2, 6+0.1, 0.3);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 5+0.2, 6+0.1, 0.3);

    // Left Arm
    drawFilledCircle(0.0f, 0.0f, 0.0f, 3.0, 4, 1.0);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.0, 3.8, 0.6);

    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.0 - 0.5, 4.4, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.0, 4.6, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.0 + 0.5, 4.4, 0.2);
    
    // Right Arm
    drawFilledCircle(0.0f, 0.0f, 0.0f, 7, 4, 1.0);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 7, 3.8, 0.6);

    drawFilledCircle(0.85f, 0.63f, 0.90f, 7 - 0.5, 4.4, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 7, 4.6, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 7 + 0.5, 4.4, 0.2);

    // Left foot
    drawFilledCircle(0.0f, 0.0f, 0.0f, 3.5, 1, 1.0);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.5, 0.8, 0.6);

    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.5-0.5, 1.4, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.5, 1.6, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 3.5+0.5, 1.4, 0.2);

    // Right foot
    drawFilledCircle(0.0f, 0.0f, 0.0f, 6.5, 1, 1.0);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 6.5, 0.8, 0.6);

    drawFilledCircle(0.85f, 0.63f, 0.90f, 6.5 - 0.5, 1.4, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 6.5, 1.6, 0.2);
    drawFilledCircle(0.85f, 0.63f, 0.90f, 6.5 + 0.5, 1.4, 0.2);

    //drawWireFrameCircle(0.0f,1.0f,0.0f,2,2,1,5);
    //drawFilledCircle(1.0f, 0.0f, 0.0f, 3, 3, 1);

    glutSwapBuffers();
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
    // update thescreen dimensions
    width = w;
    height = h;

    //do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    //glViewport((GLsizei) width/2, (GLsizei) height/2, (GLsizei) width, (GLsizei) height);

    glutPostRedisplay();
}

// Increases or decreases number of verts in displayed shapes
// Won't go below 3 verts
void keyboard(unsigned char key, int x, int y)
{
    switch (key){
    case '+':
        if (verticies < 100)
        {
            verticies++;
        }
        break;
    case '-':
        if (verticies > 3) {
            verticies--;
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    // before create a glut window,
    // initialize stuff not opengl/glut dependent
    init();

    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    //set the initial window size */
    glutInitWindowSize((int)width, (int)height);

    // create the window with a title
    glutCreateWindow("First OpenGL Program");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    //register function that draws in the window
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}
