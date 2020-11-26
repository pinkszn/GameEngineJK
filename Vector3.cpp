#include"Vector3.h"
#include<iostream>

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::SetValue(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::GetValue() {
	Vector3 value(x, y, z);
	return value;
}

Vector3 Vector3::operator+ (const Vector3 W) {
	Vector3 Result;
	Result.x = this->x + W.x;
	Result.y = this->y + W.y;
	Result.z = this->z + W.z;
	return Result;
}

void Vector3::operator+= (const Vector3 W) {
	this->x += W.x;
	this->y += W.y;
	this->z += W.z;
}

Vector3 Vector3::operator- (const Vector3 W) {
	Vector3 Result;
	Result.x = this->x - W.x;
	Result.y = this->y - W.y;
	Result.z = this->z - W.z;
	return Result;
}

void Vector3::operator-= (const Vector3 W) {
	this->x -= W.x;
	this->y -= W.y;
	this->z -= W.z;
}

Vector3 Vector3::operator* (const float W) {
	Vector3 Result;
	Result.x = this->x * W;
	Result.y = this->y * W;
	Result.z = this->z * W;
	return Result;
}

void Vector3::operator*= (const Vector3 W) {
	this->x *= W.x;
	this->y *= W.y;
	this->z *= W.z;
}

Vector3 Vector3::operator/ (const Vector3 W) {
	Vector3 Result;
	Result.x = this->x / W.x;
	Result.y = this->y / W.y;
	Result.z = this->z / W.z;
	return Result;
}

void Vector3::operator/= (const Vector3 W) {
	this->x /= W.x;
	this->y /= W.y;
	this->z /= W.z;
}

bool Vector3::operator==(const Vector3 W) {
	return ((int)(this->x * 1000.0f) == (int)(W.x * 1000.0f) && (int)(this->y * 1000.0f) == (int)(W.y * 1000.0f)
		&& (int)(this->z * 1000.0f) == (int)(W.z * 1000.0f));
}
