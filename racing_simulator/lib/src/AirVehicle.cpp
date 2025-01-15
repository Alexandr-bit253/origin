#include "AirVehicle.h"
#include "utilsDll.h"


AirVehicle::AirVehicle(std::string name, double speed)
	: name(name), speed(speed) {}


std::string AirVehicle::getName() {
	return name;
}


VehicleType AirVehicle::getTypeVehicle() {
	return typeVehicle;
}


double AirVehicle::calculateRaceTime(double distance) const {
	double adjustedDistance = distance;

	if (name == "Ковёр-самолёт") {
		if (distance < 1000) {
			adjustedDistance = distance;
		}
		else if (distance < 5000) {
			adjustedDistance = distance * 0.97;
		}
		else if (distance < 10000) {
			adjustedDistance = distance * 0.90;
		}
		else {
			adjustedDistance = distance * 0.95; 
		}
	}
	else if (name == "Орёл") {
		adjustedDistance = distance * 0.94;
	}
	else if (name == "Метла") {
		int thousands = static_cast<int>(distance / 1000);
		double reduction = thousands * 0.01;
		reduction = std::min(reduction, 1.0);
		adjustedDistance = distance * (1.0 - reduction);
	}

	return adjustedDistance / speed;
}