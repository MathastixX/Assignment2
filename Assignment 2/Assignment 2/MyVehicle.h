#pragma once
#include "Vehicle.hpp"


class MyVehicle : public Vehicle {

public:
	MyVehicle();
	MyVehicle(double x, double y, double z, double rotation);
	void draw();
};