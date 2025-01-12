#include "AirVehicle.h"
#include "utilsDll.h"


AirVehicle::AirVehicle(std::string name, double speed) :
	Vehicle(name, speed, AIR_VEHICLE) {}