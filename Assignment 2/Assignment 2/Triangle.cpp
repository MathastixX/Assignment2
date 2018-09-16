#include "Triangle.h"
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


Triangle::Triangle() :Shape()
{

}

Triangle::Triangle(float x1, float y1, float z1, float rotate, float a, float b, float angle,
	float depth, float r, float g, float b1) : Shape(x1, y1, z1, rotate)
{

	red = r;
	green = g;
	blue = b1;

	Alen = a;
	Blen = b;
	Angle = angle;
	Depth = depth;
}

float Triangle::GetAlen()
{
	return Alen;
}
float Triangle::GetBlen()
{
	return Blen;
}
float Triangle::GetAngle()
{
	return Angle;
}
float Triangle::GetDepth()
{
	return Depth;
}
void Triangle::SetAlen(float a)
{
	Alen = a;
}
void Triangle::SetBlen(float b)
{
	Blen = b;
}
void Triangle::SetAngle(float angle)
{
	Angle = angle;
}
void Triangle::SetDepth(float depth)
{
	Depth = depth;
}
void Triangle::draw()
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
	//THE COMMENTED OUT CODE IS WRONG. You are translating using postioninGL()
	//By using x - ... you are creating the shape at the coordinates already meaning
	//you dont need to translate the thing. 
	//SOlution to translate correctly is create the object at origin and then translate with
	//the function

	/*
	glBegin(GL_TRIANGLES);
	//Front Face
	glColor3d(1, 0, 0);
	glVertex3d((x - Alen) / 2, y, (z - Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z - Depth) / 2);
	glVertex3d((x + Alen) / 2, y, (z - Depth) / 2);
	
	//Back Face
	glColor3d(0, 1, 0);
	glVertex3d((x - Alen) / 2, y, (z + Depth) / 2);
	glVertex3d((x + Alen) / 2, y, (z + Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z + Depth) / 2);
	glEnd();

	//Bottom Face
	glColor3d(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3d((x - Alen) / 2, y, (z - Depth) / 2);
	glVertex3d((x + Alen) / 2, y, (z - Depth) / 2);
	glVertex3d((x + Alen) / 2, y, (z + Depth) / 2);
	glVertex3d((x - Alen) / 2, y, (z + Depth) / 2);
	//Opposite face from ab
	glColor3d(1, 1, 0);
	glVertex3d((x + Alen) / 2, y, (z - Depth) / 2);
	glVertex3d((x + Alen) / 2, y, (z + Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z + Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z - Depth) / 2);


	//ab face
	glColor3d(0, 1, 1);
	glVertex3d((x - Alen) / 2, y, (z - Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z - Depth) / 2);
	glVertex3d((x - Alen) / 2 + Blen * cos(Angle*PI / 180), y + Blen * sin(Angle*PI / 180), (z + Depth) / 2);
	glVertex3d((x - Alen) / 2, y, (z + Depth) / 2);
	
	*/

	glBegin(GL_TRIANGLES);
	//Front Face
	//glColor3d(1, 0, 0);
	glVertex3f(-Alen / 2, 0, - Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180),Blen * sin(Angle*PI / 180), - Depth/ 2);
	glVertex3f(Alen / 2, 0,- Depth / 2);
	
	//Back Face
	//glColor3d(0, 1, 0);
	glVertex3f(- Alen / 2, 0, Depth / 2);
	glVertex3f(Alen / 2, 0, Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180), Blen * sin(Angle*PI / 180), Depth/ 2);
	glEnd();

	//Bottom Face
	//glColor3d(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(- Alen / 2, 0, - Depth / 2);
	glVertex3f(Alen / 2, 0, - Depth / 2);
	glVertex3f(Alen / 2, 0,  Depth / 2);
	glVertex3f(- Alen / 2, 0, Depth / 2);
	//Opposite face from ab
	//glColor3d(1, 1, 0);
	glVertex3f(Alen / 2, 0, - Depth / 2);
	glVertex3f( Alen / 2, 0,  Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180),Blen * sin(Angle*PI / 180), Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180),Blen * sin(Angle*PI / 180),- Depth / 2);


	//ab face
	//glColor3d(0, 1, 1);
	glVertex3f(- Alen / 2, 0, - Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180), Blen * sin(Angle*PI / 180), - Depth / 2);
	glVertex3f(- Alen / 2 + Blen * cos(Angle*PI / 180), Blen * sin(Angle*PI / 180), Depth / 2);
	glVertex3f(- Alen / 2, 0,  Depth / 2);

	glEnd();
	glPopMatrix();
}
