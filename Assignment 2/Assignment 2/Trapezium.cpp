#include "Trapezium.h"
#include "Shape.hpp"
#include <math.h>
#define PI 3.14159265358979323846
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


Trapezium::Trapezium() :Shape()
{

}
Trapezium::Trapezium(float x1, float y1, float z1, float rotate, float a, float b,
					 float aoff, float height, float depth, float r, float g, float b1)
				     : Shape(x1, y1, z1, rotate)
{
	red = r;
	green = g;
	blue = b1;
	Alen = a;
	Blen = b;
	Height = height;
	Aoff = aoff;
	Depth = depth;
}

float Trapezium::GetAlen()
{
	return Alen;
}
float Trapezium::GetBlen()
{
	return Blen;

}
float Trapezium::GetHeight()
{
	return Height;
}
float Trapezium::GetAoff()
{
	return Aoff;
}
float Trapezium::GetDepth()
{
	return Depth;
}
void Trapezium::SetAlen(float a)
{
	Alen = a;
}
void Trapezium::SetBlen(float b)
{
	Blen = b;
}
void Trapezium::SetHeight(float height)
{
	Height = height;
}
void Trapezium::SetAoff(float aoff)
{
	Aoff = aoff;
}
void Trapezium::SetDepth(float depth)
{
	Depth = depth;
}
void Trapezium::draw()
{
	glPushMatrix();
	setColorInGL();
	positionInGL();
	/*
	glBegin(GL_LINES);
	// draw line for x axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(x, y, z);
	glVertex3f(x + 20.0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x - 70, y, z);
	// draw line for y axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y + 20.0, z);
	glVertex3f(x, y, z);
	glVertex3f(x, y - 70.0, z);
	// draw line for Z axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + 20.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z - 70.0);
	glEnd();
	*/
	//front face
	glBegin(GL_QUADS);
	//glColor3d(1, 0, 0);
	glVertex3f(- Alen / 2, 0,  - Depth / 2);
	glVertex3f( - Alen / 2 + Aoff, Height, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, - Depth / 2);
	glVertex3f(Alen / 2, 0, - Depth / 2);

	//Back face
	//glColor3d(0, 1, 0);
	glVertex3f(- Alen / 2, 0, Depth / 2);
	glVertex3f(- Alen / 2 + Aoff, Height, Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, Depth / 2);
	glVertex3f(Alen / 2, 0 , Depth / 2);

	//Top Face
	//glColor3d(0, 0, 1);
	glVertex3f(- Alen / 2 + Aoff, Height, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, Depth / 2);
	glVertex3f(- Alen / 2 + Aoff, Height, Depth / 2);

	//Bottom Face
	//glColor3d(1, 1, 0);
	glVertex3f(- Alen / 2, 0, - Depth / 2);
	glVertex3f(Alen / 2, 0, - Depth / 2);
	glVertex3f(Alen / 2, 0, Depth / 2);
	glVertex3f(- Alen / 2, 0, Depth / 2);

	//Offset a  Face
	//glColor3d(0, 1, 1);
	glVertex3f(- Alen / 2, 0, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff, Height, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff, Height,  Depth / 2);
	glVertex3f(- Alen / 2, 0, Depth / 2);

	//Other face opposite to offset a face
	//glColor3d(1, 1, 1);
	glVertex3f( Alen / 2, 0, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, - Depth / 2);
	glVertex3f(- Alen / 2 + Aoff + Blen, Height, Depth / 2);
	glVertex3f(Alen / 2, 0, Depth / 2);

	glEnd();
	glPopMatrix();
}