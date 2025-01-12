#include "GroundVehicle.h"
#include "utilsDll.h"


GroundVehicle::GroundVehicle(std::string name, double speed) :
	Vehicle(name, speed, GROUND_VEHICLE) {}