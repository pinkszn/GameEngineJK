#ifndef COLLIDER_H
#define COLLIDER_H

#include "Vector3.h"

class Collider {
private:
	Vector3 position;
	Vector3 scale;
	//Add a boolean that enables/disables collision detection
public:
	Collider();
	Vector3 GetPosition();
	Vector3 GetScale();

	void SetDimension(Vector3 position, Vector3 size);
	//AABB checker
	bool CheckCollision(Collider other);
	//Add more collision logic/other collision algorithms
	//Add a visualization for the collider


};


#endif
