#pragma once

// This is answer to Question 1

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