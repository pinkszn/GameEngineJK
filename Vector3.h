#ifndef VECTOR3_H
#define VECTOR3_H



class Vector3 {
public:
	float x, y, z;
	//consturctor
	Vector3();
	Vector3(float x, float y, float z);

	//Setter and Getter
	void SetValue(float x, float y, float z);
	//void SetColorValue(float r, float g, float b, float a);
	Vector3 GetValue();


	//addition
	Vector3 operator+ (const Vector3 W);
	void operator+= (const Vector3 W);
	Vector3 operator- (const Vector3 W);
	void operator-= (const Vector3 W);
	Vector3 operator* (const float W);
	void operator*= (const Vector3 W);
	Vector3 operator/ (const Vector3 W);
	void operator/= (const Vector3 W);
	bool operator==(const Vector3 W);
	
};
#endif // !VECTOR3D_H
