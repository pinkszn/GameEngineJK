#include "Graphics.h"

void ChangeSize(int width, int height)
{
	// Prevent divide by 0
	if (height == 0)
		height = 1;
	float ratio = 1.0 * width / height;
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset Matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);
	// Set the correct perspective.
	glOrtho(-10,10,-10,10,1,-1);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//The function that is called every frame
	Update();

	glutSwapBuffers();
}