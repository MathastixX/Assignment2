#pragma once
#include "Shape.hpp"

class Rectangular : public Shape
{
protected:
	float xlen;
	float ylen;
	float zlen;

public:
	Rectangular();
	Rectangular(float x1, float y1, float z1, float rotation, float xlen, float ylen, float zlen,
				float r, float g, float b1);
	float Getxlen();
	float Getylen();
	float Getzlen();
	void Setxlen(float x);
	void Setylen(float y);
	void Setzlen(float z);
	void draw();


};