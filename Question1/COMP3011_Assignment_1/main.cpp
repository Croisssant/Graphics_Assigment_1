#include <iostream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void tetraInCube(float r);
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

	GLFWwindow* window = glfwCreateWindow(600, 600, "Question 1", NULL, NULL);


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

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glDepthFunc(GL_LESS);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);

		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glRotatef(0.01f, 1.f, 1.f, 1.f);

		float r = 0.5f;

		// This is answer to Question 1
		tetraInCube(r);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();
	return 0;
}
void tetraInCube(float r) {

	// === The Tetrahedron ===
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // Red
	glVertex3f(-r, r, -r); // Yellow Magenta Green
	glVertex3f(r, r, r); // White Red Magenta
	glVertex3f(r, -r, -r); // Green White Cyan

	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Blue
	glVertex3f(-r, r, -r); // Yellow Magenta Green
	glVertex3f(r, -r, -r); // Green White Cyan
	glVertex3f(-r, -r, r); // Cyan Red Yellow

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // Green
	glVertex3f(r, r, r); // White Red Magenta
	glVertex3f(-r, -r, r); // Cyan Red Yellow
	glVertex3f(r, -r, -r); // Green White Cyan

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // White
	glVertex3f(-r, -r, r); // Cyan Red Yellow
	glVertex3f(r, r, r); // White Red Magenta
	glVertex3f(-r, r, -r); // Yellow Magenta Green



	// === The Cube ===
	// Back Face
	glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red
	glVertex3f(-r, -r, r);
	glVertex3f(-r, r, r);
	glVertex3f(r, r, r);

	glVertex3f(r, r, r);
	glVertex3f(r, -r, r);
	glVertex3f(-r, -r, r);


	// Near Face
	glColor4f(0.0f, 1.0f, 0.0f, 0.5f); // Green
	glVertex3f(-r, -r, -r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, r, -r);

	glVertex3f(r, r, -r);
	glVertex3f(r, -r, -r);
	glVertex3f(-r, -r, -r);


	// Right Face
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // White
	glVertex3f(r, -r, r);
	glVertex3f(r, r, r);
	glVertex3f(r, r, -r);

	glVertex3f(r, r, -r);
	glVertex3f(r, -r, -r);
	glVertex3f(r, -r, r);


	//Left Face
	glColor4f(1.0f, 1.0f, 0.0f, 0.5f); // Yellow
	glVertex3f(-r, -r, r);
	glVertex3f(-r, r, r);
	glVertex3f(-r, r, -r);

	glVertex3f(-r, r, -r);
	glVertex3f(-r, -r, -r);
	glVertex3f(-r, -r, r);


	//Bottom Face
	glColor4f(1.0f, 0.0f, 1.0f, 0.5f); // Magenta
	glVertex3f(-r, r, r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, r, -r);

	glVertex3f(r, r, -r);
	glVertex3f(r, r, r);
	glVertex3f(-r, r, r);


	//Top Face
	glColor4f(0.0f, 1.0f, 1.0f, 0.5f); // Cyan
	glVertex3f(-r, -r, r);
	glVertex3f(-r, -r, -r);
	glVertex3f(r, -r, -r);

	glVertex3f(r, -r, -r);
	glVertex3f(r, -r, r);
	glVertex3f(-r, -r, r);

	glEnd();

}