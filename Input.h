#ifndef INPUT_H
#define INPUT_H

struct KeyCode {
	static int A() { return 97; }
	static int D() { return 100; }
	static int S() { return 115; }
	static int W() { return 119; }
	static int space() { return 32; }
};

class Input {
public:
	static bool keyPress[256];
	static bool GetKey(unsigned char key);
	//function that will detect if the key is being held down
	static bool GetKeyDown(unsigned char key);
	//TODO: function that will detect if the key is pressed once
	//TODO: improve the get key up function to only return true once when the key has been released after being pressed
	static bool GetKeyUp(unsigned char key);
};

extern void keyPressed(unsigned char key, int x, int y);
extern void keyPressedUp(unsigned char key, int x, int y);

#endif