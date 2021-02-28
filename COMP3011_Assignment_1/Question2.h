#pragma once

// TESTING FUNCTION
void drawSolidCube2(float r) {

	glBegin(GL_QUADS);

	// Near face
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(-r, -r, r);
	glVertex3f(-r, r, r);
	glVertex3f(r, r, r);
	glVertex3f(r, -r, r);
	// Back face
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(-r, -r, -r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, r, -r);
	glVertex3f(r, -r, -r);
	// Right face
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(r, -r, r);
	glVertex3f(r, r, r);
	glVertex3f(r, r, -r);
	glVertex3f(r, -r, -r);
	// Left face
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(-r, -r, r);
	glVertex3f(-r, r, r);
	glVertex3f(-r, r, -r);
	glVertex3f(-r, -r, -r);
	// Bottom face
	glColor3f(1.0f, 0.0f, 1.0f); // Magenta
	glVertex3f(-r, r, r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, r, -r);
	glVertex3f(r, r, r);
	// Top face
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
	glVertex3f(-r, -r, r);
	glVertex3f(-r, -r, -r);
	glVertex3f(r, -r, -r);
	glVertex3f(r, -r, r);

	glEnd();

}