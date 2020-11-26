#include "GameObject.h"

#include <glut.h>

//constructor
GameObject::GameObject() {
	SetPosition(0, 0, 0);
	SetRotation(0, 0, 0, 0);
	SetScale(1, 1, 1);
	collider.SetDimension(position, scale);
}

Collider GameObject::GetCollider() {
	return collider;
}

bool GameObject::CheckCollision(GameObject other) {
	return collider.CheckCollision(other.GetCollider());
}

void GameObject::SetPosition(float x, float y, float z) {
	position.SetValue(x, y, z);
}

void GameObject::SetPosition(Vector3 position) {
	this->position = position;
}

void GameObject::SetRotation(float angle, float x, float y, float z) {
	this->rotationAngle = angle;
	this->xAxisRotation = x;
	this->yAxisRotation = y;
	this->zAxisRotation = z;
}

void GameObject::SetScale(float x, float y, float z) {
	scale.SetValue(x, y, z);
}

void GameObject::Translate(Vector3 position) {
	this->position.x = position.x;
	this->position.y = position.y;
	this->position.z = position.z;
}

void GameObject::DrawCube() {
	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);
	//glColor3f(Color.r, Color.g, Color.b) or glColor3f(Color.x, Color.y, Color.z)
	glRotatef(this->rotationAngle, this->xAxisRotation, this->yAxisRotation, this->zAxisRotation);
	glScalef(this->scale.x, this->scale.y, this->scale.z);
	glutSolidCube(1.0f);
	glPopMatrix();

	//update the collider
	collider.SetDimension(position, scale);
}

void GameObject::RenderMap() {
	position.x = 1;
	position.y = 1;

	glPushMatrix();
	for (int i = -5; i <= 5; i++) {
		for (int i = -5; i <= 5; i++) {
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
			glVertex3f(position.x + i, position.y, position.z);
			glVertex3f(-position.x + i, position.y, position.z);
			glVertex3f(-position.x + i, -position.y, position.z);
			glVertex3f(position.x + i, -position.y, position.z);
			glEnd();
			for (int j = -5; j < 5; j++) {
				glBegin(GL_LINE_LOOP);
				glVertex3f(position.x + i, position.y + j, position.z);
				glVertex3f(-position.x + i, position.y + j, position.z);
				glVertex3f(-position.x + i, -position.y + j, position.z);
				glVertex3f(position.x + i, -position.y + j, position.z);
				glEnd();
			}
		}
	}
}