#include <cmath>

#include "GroundVehicle.h"
#include "utilsDll.h"


GroundVehicle::GroundVehicle(std::string name, double speed, double timeUntilRest, std::vector<double> restDuration) 
	:  name(name), speed(speed), timeUntilRest(timeUntilRest), restDuration(restDuration) {}


std::string GroundVehicle::getName() {
	return name;
}


VehicleType GroundVehicle::getTypeVehicle() {
	return typeVehicle;
}


double GroundVehicle::calculateRaceTime(double distance) const {
	double travelTime = distance / speed;
	int restStops = static_cast<int>(std::ceil(travelTime / timeUntilRest));

	double totalRestTime{ 0.0 };
	for (int i = 0; i < restStops; ++i) {
		if (i > restDuration.size() - 1) {
			totalRestTime += restDuration.back();
		}
		else {
			totalRestTime += restDuration[i];
		}
	}

	double totalTimeWithRest = travelTime + totalRestTime;
	if (totalTimeWithRest - totalRestTime >= travelTime) {
		totalTimeWithRest -= restDuration.back();
	}

	return totalTimeWithRest;
}