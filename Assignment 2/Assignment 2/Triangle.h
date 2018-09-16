#pragma once
#include "Shape.hpp"


class Triangle : public Shape
{
protected:
	float Alen;		//length of side A (bottom)
	float Blen;		// length of side B (left)
	float Angle;	//angle (degrees) between side A and B
	float Depth;	//length along z axis

public:
	Triangle();
	Triangle(float x1, float y1, float z1, float rotate, float Alen, float Blen, float Angle,
		float Depth, float red, float green, float blue);
	//Triangle(float Alen, float Blen, float Angle, float Depth);
	float GetAlen();
	float GetBlen();
	float GetAngle();
	float GetDepth();
	void SetAlen(float a);
	void SetBlen(float b);
	void SetAngle(float angle);
	void SetDepth(float depth);
	void draw();
};
