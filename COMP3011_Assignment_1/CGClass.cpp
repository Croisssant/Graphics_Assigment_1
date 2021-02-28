#include <GLFW/glfw3.h>
#include "math.h"
#include <iostream>

using namespace std;
float x = 0.0f;
float y = 0.0f;
float z = 0.0f;

float o = 0.0f;
float p = 0.0f;
float q = 0.0f;

float a = 0.0f;
float b = 0.0f;
//Declare keyboard method
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void drawFirst(float r);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 800, "Class", NULL, NULL);
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
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //Change the direction and size of the figure to become an airplane shape
        glScalef(0.1f, 0.1f, 0.1f);
        glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        //Rotate around 3 axes through variables
        glRotatef(x, 1.0f, 0.0f, 0.0f);
        glRotatef(y, 0.0f, 1.0f, 0.0f);
        glRotatef(z, 0.0f, 0.0f, 1.0f);
        //Move forward
        glTranslatef(a, a, a);

        drawFirst(1.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //Change the direction and size of the figure to become an airplane shape
        glScalef(0.1f, 0.1f, 0.1f);
        glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
        //Rotate around 3 axes through variables
        glRotatef(o, 1.0f, 0.0f, 0.0f);
        glRotatef(p, 0.0f, 1.0f, 0.0f);
        glRotatef(q, 0.0f, 0.0f, 1.0f);

        glTranslatef(-7.0f, 0.0f, 2.0f);
        //Move forward
        glTranslatef(b, b, b);

        drawFirst(1.0f);
        
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

//Key operation method  Change the variable to change the direction of the airplane
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        z += 5.0f;
    }
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        z -= 5.0f;
    }
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        x -= 5.0f;
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        x += 5.0f;
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        y += 5.0f;
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        y -= 5.0f;
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS)
    {
        a += 0.1f;
    }
    if (key == GLFW_KEY_U && action == GLFW_PRESS)
    {
        q += 5.0f;
    }
    if (key == GLFW_KEY_O && action == GLFW_PRESS)
    {
        q -= 5.0f;
    }
    if (key == GLFW_KEY_I && action == GLFW_PRESS)
    {
        o -= 5.0f;
    }
    if (key == GLFW_KEY_K && action == GLFW_PRESS)
    {
        o += 5.0f;
    }
    if (key == GLFW_KEY_J && action == GLFW_PRESS)
    {
        p += 5.0f;
    }
    if (key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        p -= 5.0f;
    }
    if (key == GLFW_KEY_H && action == GLFW_PRESS)
    {
        b += 0.1f;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;

        o = 0.0f;
        p = 0.0f;
        q = 0.0f;

        a = 0.0f;
        b = 0.0f;
    }
}

void drawFirst(float r) {
    glBegin(GL_TRIANGLES); 
    //Draw vertex coordinates and colors
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, r, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-r, -r, r);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(r, -r, r);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, r, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(r, -r, r);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(r, -r, -r);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, r, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(r, -r, -r);
    glColor3f(0.0f, 0.0f, r);
    glVertex3f(-r, -r, -r);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, r, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-r, -r, -r);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-r, -r, r);

    glEnd();
}


