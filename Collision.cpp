#include "Collider.h"

Collider::Collider() {
	position.SetValue(0, 0, 0);
	scale.SetValue(1, 1, 1);
}

Vector3 Collider::GetPosition() { return position; }
Vector3 Collider::GetScale() { return scale; }

void Collider::SetDimension(Vector3 position, Vector3 scale) {
	this->position = position;
	this->scale = scale;
}

bool Collider::CheckCollision(Collider other) {
	//Assuming the pivot is at the center of the gameobject
	float xSize = scale.x / 2;
	float ySize = scale.y / 2;
	float zSize = scale.z / 2;

	float xSizeOther = other.scale.x / 2;
	float ySizeOther = other.scale.y / 2;
	float zSizeOther = other.scale.z / 2;

	//Axis-Aligned Bounding Box (AABB Collider)
	//SUMMARY: "If the AABBS do not overlap, the bodies do not collide. If the AABBS overlap, the bodies may collide

	//Check whether the x of collider is completely left/right of the other collider
	bool xCollision = position.x - xSize > other.position.x + xSizeOther ||
		position.x + xSize < other.position.x - xSizeOther;

	//Check whether the y of collider is completely above/below of the other collider
	bool yCollision = position.y - ySize > other.position.y + ySizeOther ||
		position.y + ySize < other.position.y - ySizeOther;

	//Check whether the z of collider is completely in front/behind of the other collider
	bool zCollision = position.z - zSize > other.position.z + zSizeOther ||
		position.z + zSize < other.position.z - zSizeOther;

	//if the collider is somewhere completely left/right/up/below/in front/behind the collider, then we assume no collision is happening
	if (xCollision || yCollision || zCollision)
		return false;
	//otherwise there is an overlapping happening
	else
		return true;
}