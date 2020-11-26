#include "GameEngine.h"
#include<time.h>
#include<iostream>


GameObject cube, anotherCube, map;
GameObject eBullet1;
bool isShooting = false;
int random;

Vector3 cubePosition(0.5f, -5.5f, 0.0f);
Vector3 eBulletPosition(0, 5, 0);

Vector3 movement(0.5f, 0.0f, 0.0f);

void Initialize() {
	eBullet1.SetScale(1, 1, 1);
	cube.SetScale(0.5, 0.5, 0.5);
	cube.SetRotation(0, 0, 0, 1);
	map.RenderMap();
}

void RandomBulletDrop() {
	
	if (eBulletPosition.y <= -6) {
		isShooting = false;
		eBulletPosition.y = 5;
	}

	if (isShooting == false) {						
		random = rand() % (4 + 1 + 4) - 5;
		eBulletPosition.x = random;
		std::cout << random;
	}

	isShooting = true;

	if (isShooting == true) {
		eBulletPosition.y -= 0.15;
		eBullet1.Translate(Vector3(eBulletPosition.x, eBulletPosition.y, 0.0f));
		eBullet1.DrawCube();
	}
}

void Inputs() {
	if (Input::GetKey(KeyCode::W()) && cubePosition.y <= 4) {
		cubePosition.y += 0.25f;
	}

	if (Input::GetKey(KeyCode::D()) && cubePosition.x <= 5) {
		//std::cout << "Pressed the a button." << std::endl;
		cubePosition.x += 0.25f;
	}
	if (Input::GetKey('s') && cubePosition.y >=-5) {
		cubePosition.y -= 0.25f;
	}

	if (Input::GetKey(KeyCode::A()) && cubePosition.x >= -5) {
		cubePosition.x -= 0.25f;
	}

	if (Input::GetKeyDown (KeyCode::space())){
		std::cout << "The spacebar is up\n";
}

	if (cube.CheckCollision(eBullet1)) {
		std::cout << "We have collided." << std::endl;
	}
}

void Update() {
	srand(time(NULL));
	RandomBulletDrop();
	Inputs();
	cube.SetPosition(cubePosition);
	cube.DrawCube();

#pragma region map
	map.RenderMap();
#pragma endregion
}



int main(int argc, char** argv) {
	PrepareEngine(&argc, argv);
}