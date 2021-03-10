#include <GLFW/glfw3.h>
#include "math.h"
#include <iostream>

using namespace std;

//Init subdivision depth
unsigned int DEPTH = 3;

//Octagonal vertex coordinates
GLfloat vertex[][3] = {
  0.0f,  1.0f,  0.0f,
  0.0f,  0.0f,  1.0f,
  1.0f,  0.0f,  0.0f,
  0.0f,  0.0f, -1.0f,
 -1.0f,  0.0f,  0.0f,
  0.0f, -1.0f,  0.0f
};
//Declare keyboard method
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int depth, int face_number);
void normalize(GLfloat* v);
void triangle(GLfloat* va, GLfloat* vb, GLfloat* vc);
void draw();
int main(void)
{
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Question 2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Set the plane surrounded by the counterclockwise points as the front
        glFrontFace(GL_CCW);
        // Set not to draw the back side, saving computing power and preventing the back side from covering the front side
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef((float)glfwGetTime() * 5.0f, 1.0f, 1.0f, 0.0f);

        draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

//Key operation method  Change depth by up and down
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        DEPTH += 1;
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        DEPTH -= 1;
    }
}

/*Map the subdivided triangles to the unit sphere by normalization
scale the distance from the vertex to the origin from the original distance to 1*/
void normalize(GLfloat* v)
{
    GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] /= d; v[1] /= d; v[2] /= d;
}

/*The way to divide the sides equally, the equilateral triangle is further subdivided into four equilateral triangles,
Start to subdivide recursively, if the number of layers is not reached, the triangle is further subdivided, and if the depth drops to 0, the final small triangle is drawn*/

void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int depth, int face_number)
{
    if (depth > 0) {
        //Temporary points are used to store midpoints
        GLfloat ab[3], bc[3], ac[3];

        for (unsigned int i = 0; i < 3; i++)
            ab[i] = (a[i] + b[i]) / 2;
        normalize(ab);
        for (unsigned int i = 0; i < 3; i++)
            bc[i] = (b[i] + c[i]) / 2;
        normalize(bc);
        for (unsigned int i = 0; i < 3; i++)
            ac[i] = (a[i] + c[i]) / 2;
        normalize(ac);


        divide_triangle(a, ac, ab, depth - 1, 1);

        divide_triangle(b, ab, bc, depth - 1, 2);

        divide_triangle(c, bc, ac, depth - 1, 3);

        divide_triangle(ab, ac, bc, depth - 1, 4);
    }
    else {

        if (face_number == 1)
        {
            glColor3f(1.0, 0.0, 0.0);
            triangle(a, b, c);
        }
        else if (face_number == 2)
        {
            glColor3f(0.0, 0.0, 1.0);
            triangle(a, b, c);
        }
        else if (face_number == 3)
        {
            glColor3f(0.0, 0.0, 0.0);
            triangle(a, b, c);
        }
        else {

            glColor3f(0.0, 1.0, 0.0);
            triangle(a, b, c);
        }

    }
}
void triangle(GLfloat* va, GLfloat* vb, GLfloat* vc)
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
    glEnd();
    glFlush();
}
void draw() {
    divide_triangle(vertex[0], vertex[2], vertex[1], DEPTH, 1);
    divide_triangle(vertex[0], vertex[3], vertex[2], DEPTH, 2);
    divide_triangle(vertex[0], vertex[4], vertex[3], DEPTH, 3);
    divide_triangle(vertex[0], vertex[1], vertex[4], DEPTH, 4);
    divide_triangle(vertex[5], vertex[1], vertex[2], DEPTH, 4);
    divide_triangle(vertex[5], vertex[2], vertex[3], DEPTH, 3);
    divide_triangle(vertex[5], vertex[3], vertex[4], DEPTH, 2);
    divide_triangle(vertex[5], vertex[4], vertex[1], DEPTH, 1);
}
