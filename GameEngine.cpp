#include "GameEngine.h"
#include "Graphics.h"
#include<time.h>
#include<box2d/box2d.h>

void PrepareEngine(int* argc, char** argv) {
	glutInit(argc, argv);

	// Do double-buffer for smoother rendering and animation.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game Engine");
		
	//This function will only run once at the Initialization of the engine
	Initialize();

	glutDisplayFunc(&RenderScene);
	glutReshapeFunc(&ChangeSize);
	glutIdleFunc(&RenderScene);

	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyPressedUp);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}