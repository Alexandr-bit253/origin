#include "Vehicle.h"


Vehicle::Vehicle(std::string name, double speed, VehicleType typeVehicle)
	: name(name), speed(speed), typeVehicle(typeVehicle) {}


VehicleType Vehicle::getTypeVehicle() {
	return typeVehicle;
}


std::string Vehicle::getName() {
	return name;
}


double Vehicle::getSpeed() const {
	return speed;
}