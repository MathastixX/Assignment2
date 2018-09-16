#include "Rectangular.h"
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

Rectangular::Rectangular()
{

}
Rectangular::Rectangular(float x1, float y1, float z1, float rotation, float xlength,
					float ylength, float zlength, float r, float g, float b1) 
					:Shape(x1, y1, z1, rotation)
{
	xlen = xlength;
	ylen = ylength;
	zlen = zlength;
	red = r;
	green = g;
	blue = b1;
}
float Rectangular::Getxlen() 
{
	return xlen;
} 
float Rectangular::Getylen() 
{
	return ylen;
}
float Rectangular::Getzlen() 
{
	return zlen;
}
void Rectangular::Setxlen(float x) 
{
	xlen = x;
}
void Rectangular::Setylen(float y) 
{
	ylen = y;
} 
void Rectangular::Setzlen(float z) 
{
	zlen = z;
}
void Rectangular::draw()
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
	/*
	glBegin(GL_QUADS);
	//Front face
	glColor3d(1, 1, 1);
	glVertex3f((x - xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen, (z - zlen) / 2);
	glVertex3f((x - xlen) / 2, y + ylen, (z - zlen) / 2);

	//Back Face
	glColor3d(1, 1, 0);
	glVertex3f((x - xlen) / 2, y, (z + zlen) / 2);
	glVertex3f((x + xlen) / 2, y, (z + zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen, (z + zlen) / 2);
	glVertex3f((x - xlen) / 2, y + ylen, (z + zlen) / 2);

	//Left Face
	glColor3d(1, 0, 0);
	glVertex3f((x - xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x - xlen) / 2, y + ylen, (z - zlen) / 2);
	glVertex3f((x - xlen) / 2, y + ylen, (z + zlen) / 2);
	glVertex3f((x - xlen) / 2, y, (z + zlen) / 2);
	
	//Right Face
	glColor3d(1, 0, 1);
	glVertex3f((x + xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y, (z + zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen, (z + zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen , (z - zlen) / 2);

	//Top Face
	glColor3d(0, 1, 0);
	glVertex3f((x - xlen) / 2, y + ylen, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y + ylen, (z + zlen) / 2);
	glVertex3f((x - xlen) / 2, y + ylen, (z + zlen) / 2);

	//Botton Face
	glColor3d(0, 0, 1);
	glVertex3f((x - xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y, (z - zlen) / 2);
	glVertex3f((x + xlen) / 2, y, (z + zlen) / 2);
	glVertex3f((x - xlen) / 2, y, (z + zlen) / 2);
	*/

	glBegin(GL_QUADS);
	//Front face
	//glColor3d(1, 1, 1);
	glVertex3f(- xlen/ 2, 0, (- zlen) / 2);
	glVertex3f(xlen / 2, 0, ( - zlen) / 2);
	glVertex3f(xlen / 2,ylen, ( - zlen) / 2);
	glVertex3f(- xlen / 2, ylen, ( - zlen) / 2);

	//Back Face
	//glColor3d(1, 1, 0);
	glVertex3f(( - xlen) / 2, 0, ( + zlen) / 2);
	glVertex3f(( + xlen) / 2, 0, ( + zlen) / 2);
	glVertex3f(( + xlen) / 2, 0 + ylen, ( + zlen) / 2);
	glVertex3f(( - xlen) / 2, 0 + ylen, ( + zlen) / 2);

	//Left Face
	//glColor3d(1, 0, 0);
	glVertex3f(( - xlen) / 2, 0, ( - zlen) / 2);
	glVertex3f(( - xlen) / 2, 0 + ylen, ( - zlen) / 2);
	glVertex3f(( - xlen) / 2, 0 + ylen, ( + zlen) / 2);
	glVertex3f(( - xlen) / 2, 0, (0 + zlen) / 2);

	//Right Face
	//glColor3d(1, 0, 1);
	glVertex3f(( + xlen) / 2, 0, (0 - zlen) / 2);
	glVertex3f(( + xlen) / 2, 0, (0 + zlen) / 2);
	glVertex3f(( + xlen) / 2, 0 + ylen, (0 + zlen) / 2);
	glVertex3f(( + xlen) / 2, 0 + ylen, (0 - zlen) / 2);

	//Top Face
	//glColor3d(0, 1, 0);
	glVertex3f((0 - xlen) / 2, 0 + ylen, (0 - zlen) / 2);
	glVertex3f((0 + xlen) / 2, 0 + ylen, (0 - zlen) / 2);
	glVertex3f((0 + xlen) / 2, 0 + ylen, (0 + zlen) / 2);
	glVertex3f((0 - xlen) / 2, 0 + ylen, (0 + zlen) / 2);

	//Botton Face
	//glColor3d(0, 0, 1);
	glVertex3f((0 - xlen) / 2, 0, (0 - zlen) / 2);
	glVertex3f((0 + xlen) / 2, 0, (0 - zlen) / 2);
	glVertex3f((0 + xlen) / 2, 0, (0 + zlen) / 2);
	glVertex3f((0 - xlen) / 2, 0, (0 + zlen) / 2);


	glEnd();
	glPopMatrix();
}