#pragma once
#include "Shape.hpp"

class Cylinder : public Shape {
protected:
	float Radius;
	float Depth;
	bool isRolling;
	bool isSteering;

public:
	Cylinder();
	Cylinder(float x1, float y1, float z1, float rotation, float radius, float depth, float r, float g,
			float b1);
	float GetRadius();
	float GetDepth();
	void SetRadius(float radius);
	void SetDepth(float depth);
	void draw();

};