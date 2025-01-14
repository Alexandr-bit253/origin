#include "AirVehicle.h"
#include "utilsDll.h"


AirVehicle::AirVehicle(std::string name, double speed, std::vector<double> restDuration)
	: Vehicle(typeVehicle),
	name(name),
	speed(speed),
	restDuration(restDuration) {}


std::string AirVehicle::getName() {
	return name;
}


double AirVehicle::calculateRaceTime(double distance) const {
	return 0.0;
}