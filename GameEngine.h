#ifndef GAMEENGINE_H
#define GAMEENGINE_H
//Include all headers/libraries needed for the game engine to run

#include<iostream>
#include<glut.h>

#include"Input.h"
#include"GameObject.h"

void Initialize();
void Update();
void PrepareEngine(int* argc, char** argv);
void keyPressed(unsigned char key, int x, int y);
void keyPressedUp(unsigned char key, int x, int y);

#endif