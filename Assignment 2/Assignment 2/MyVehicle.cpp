
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

#include "MyVehicle.h"
#include "Vehicle.hpp"
#include <math.h>
#include "Rectangular.h"
#include "Trapezium.h"
#include "Cylinder.h"
#include "Triangle.h"
#include <vector>
#include "Messages.hpp"
#define PI 3.14159265358979323846

MyVehicle::MyVehicle()
{
	//ShapeInit section;
	//Wheelmount Section
	
	/*section.type = RECTANGULAR_PRISM;
	section.params.rect.xlen = 15.0;
	section.params.rect.ylen = 1.5;
	section.params.rect.zlen = 5.0;
	section.xyz[0] = 0.0;
	section.xyz[1] = 2.0;
	section.xyz[2] = 0.0;
	section.rotation = 0.0;
	section.rgb[0] = 1.0;
	section.rgb[1] = 0.0;
	section.rgb[2] = 0.0;
	*/
	//shapes.push_back(section);



	


}

MyVehicle::MyVehicle(double x, double y, double z, double rotation)
{
}

void MyVehicle::draw()
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}

	/*//glScaled(0.5, 0.5, 0.5);
	glPushMatrix();
	positionInGL();
	//WheelMount
	Rectangular WheelMount(0, 1, 0, 0, 15, 1.5, 5, 1, 0, 0);
	WheelMount.draw();

	//Back Wheel (x/2 +10, y , z/2 + depth/2)  radius y clearance+ height
	Cylinder LBackWheel(-5, 0, -2.5 - 0.25, 0, 2, 0.5, 0, 1, 0);
	LBackWheel.draw();

	Cylinder LFrontWheel(5, 0, -2.5 - 0.25, 0, 2, 0.5, 0, 1, 0);
	LFrontWheel.draw();

	Cylinder RBackWheel(-5, 0, 2.5 + 0.25, 0, 2, 0.5, 0, 1, 0);
	RBackWheel.draw();

	Cylinder RFrontWheel(5, 0, 2.5 + 0.25, 0, 2, 0.5, 0, 1, 0);
	RFrontWheel.draw();

	Trapezium Body(0, 2.5, 0, 0, 15, 5, 2.5, 2, 5, 0, 0, 1);
	Body.draw();

	Triangle FBumper(8.25, 1, 0, 0, 1.5, 1.5, 90, 5, 1, 1, 1);
	FBumper.draw();

	glPopMatrix();
	*/
}
