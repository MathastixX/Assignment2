#pragma once
#include "Shape.hpp"

class Trapezium : public Shape
{
protected:
	float Alen;
	float Blen;
	float Height;
	float Aoff;
	float Depth;


public:
	Trapezium();
	Trapezium(float x1, float y1, float z1, float rotation, float a, float b,
              float aoff,float height, float depth, float red, float green, float blue);
	float GetAlen();
	float GetBlen();
	float GetHeight();
	float GetAoff();
	float GetDepth();
	void SetAlen(float a);
	void SetBlen(float b);
	void SetHeight(float height);
	void SetAoff(float aoff);
	void SetDepth(float depth);
	void draw();

};
