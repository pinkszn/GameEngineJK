#include "Input.h"

//initialize the static variable
bool Input::keyPress[256] = { false };

//function that will return whether the key is being pressed down
bool Input::GetKey(unsigned char key) {
	return keyPress[key];
}

//function that will only return true once the key is not being pressed anymore
//TODO: improve this function
bool Input::GetKeyUp(unsigned char key) {
	if (keyPress[key] == true) {
		return false;
	}
	else
		return true;
}

bool Input::GetKeyDown(unsigned char key) {
	if (keyPress[key] == true) {
		return true;
	}else
	return false;  
}

void keyPressed(unsigned char key, int x, int y) {
	Input::keyPress[key] = true;
}

void keyPressedUp(unsigned char key, int x, int y) {
	Input::keyPress[key] = false;
}

