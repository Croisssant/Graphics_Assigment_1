#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Question1.h"
#include "Question2.h"
#include "Question3.h"


int main() {



	if (!glfwInit())
	{
		std::cout << "GLFW initialisation failed." << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(600, 600, "Hellow World", NULL, NULL);


	if (!window)
	{
		std::cout << "GLFW failed to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "GLEW initialisation failed: " << glewGetErrorString(err) << std::endl;

		return -1;
	}



	glClearColor(1.0f, 0.5f, 0.6f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glRotatef(0.01f, 1.f, 1.f, 1.f);

		int choice = 1;
		float r = 0.5f;


		switch (choice)
		{
		case 1:
			// This is answer to Question 1
			tetraInCube(0.5f);
			break;

		case 2:
			drawSolidCube2(0.2f);
			break;

		case 3:
			drawSolidCube3(0.4f);
			break;

		}
		




		glfwSwapBuffers(window);
		glfwPollEvents();





	}

	glfwTerminate();
	return 0;
}