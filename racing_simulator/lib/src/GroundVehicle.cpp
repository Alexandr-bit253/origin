#include "GroundVehicle.h"
#include "utilsDll.h"


GroundVehicle::GroundVehicle(std::string name, double speed, double timeUntilRest, std::vector<double> restDuration) 
	: Vehicle(typeVehicle), 
	name(name),
	speed(speed), 
	timeUntilRest(timeUntilRest), 
	restDuration(restDuration) {}


std::string GroundVehicle::getName() {
	return name;
}


double GroundVehicle::calculateRaceTime(double distance) const {
	double travelTime = distance / speed;
	int restStops = static_cast<int>(travelTime / timeUntilRest);

	double totalRestTime{ 0.0 };
	for (int i = 0; i < restStops; ++i) {
		if (i > restDuration.size()) {
			totalRestTime += restDuration.back();
		}
		else {
			totalRestTime += restDuration[i];
		}
		/*if (i == 0) {
			totalRestTime += firstRestDuration;
		}
		else {
			totalRestTime += subsequentRestDuration;
		}*/
	}

	double totalTimeWithRest = travelTime + totalRestTime;
	if (totalTimeWithRest - totalRestTime >= travelTime) {
		totalRestTime -= restDuration.back();
		//totalRestTime -= subsequentRestDuration;
	}

	return travelTime + totalRestTime;
}