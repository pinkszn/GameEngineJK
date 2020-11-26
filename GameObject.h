#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"Vector3.h"
#include"Collider.h"
#include<box2d/box2d.h>

class GameObject {
private:

	Vector3 position;
	//Vector3 color;
	Vector3 scale;
	float rotationAngle, xAxisRotation, yAxisRotation, zAxisRotation;
	Collider collider;
	

public:
	GameObject();
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void SetRotation(float angle, float x, float y, float z);
	void SetScale(float x, float y, float z);
	/*void SetColor(float r, float g, float b, float a);*/

	void Translate(Vector3 Position);//moving the bullets
	Collider GetCollider();
	bool CheckCollision(GameObject other);
	void DrawCube();
	void Destroy();
	
	void RenderMap();
	void DrawSphere();
	//void Circle2D();


};
#endif