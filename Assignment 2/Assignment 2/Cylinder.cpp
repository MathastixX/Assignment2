
//#include "Shape.hpp"
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
#include "Cylinder.h"

Cylinder::Cylinder()
{

}
Cylinder::Cylinder(float x1, float y1, float z1, float rotation, float radius, float depth, float r,
					float g,float b1):Shape(x1,y1,z1, rotation)
{
	Radius = radius;
	Depth = depth;
	red = r;
	green = g;
	blue = b1;

}
float Cylinder::GetRadius()
{
	return Radius;
}
float Cylinder::GetDepth()
{
	return Depth;
}
void Cylinder::SetRadius(float radius)
{
	Radius = radius;
}
void Cylinder::SetDepth(float depth)
{
	Depth = depth;
}
void Cylinder::draw()
{
	glPushMatrix();

	/*glBegin(GL_LINES);
	// draw line for x axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(x, y, z);
	glVertex3f(x + 20.0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x - 20, y, z);
	// draw line for y axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y + 20.0, z);
	glVertex3f(x, y, z);
	glVertex3f(x, y - 20.0, z);
	// draw line for Z axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + 20.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z - 20.0);
	glEnd();

	*/
	glTranslated(0, Radius, -Depth/2);
	setColorInGL();
	positionInGL();
	//glColor3d(1, 0, 0);
	glBegin(GL_POLYGON);
	static GLUquadric * disk = gluNewQuadric();
	double BaseRadius = static_cast<double>(Radius);
	double TopRadius = static_cast<double>(Radius);
	double height = static_cast<double>(Depth);
	int slices = 20;
	int stack = 100;
	gluCylinder(disk, BaseRadius, TopRadius, height, slices, stack);

	//Lid

	//glColor3d(1, 1, 1);
	glTranslated(0, 0, height);
	double InnerRadius = 0;
	double OuterRadius = static_cast<double>(Radius);
	int loops = 1;
	gluDisk(disk, InnerRadius, OuterRadius, slices, loops);
	glEnd();
	glPopMatrix();
}