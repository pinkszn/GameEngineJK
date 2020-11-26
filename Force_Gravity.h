#pragma once
#ifndef FORCE_GRAVITY_H

#include"Vector3.h"

class Gravity {
public:
	Gravity();
	Gravity(Vector3 GetValue);
	Vector3 GetPosition();
	//static float applyGravity();
	//void applyForce();
	

private:
	Vector3 position;
};
#endif // !FORCE_GRAVITY_H
