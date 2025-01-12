#include "Camel.h"


Camel::Camel(std::string name, double speed) : GroundVehicle(name, speed) {}


double Camel::calculateRaceTime(double distance) const {
	double travelTime = distance / speed;
	int restStops = static_cast<int>(travelTime / timeUntilRest);

	double totalRestTime{ 0.0 };
	for (int i = 0; i < restStops; ++i) {
		if (i == 0) {
			totalRestTime += firstRestDuration;
		}
		else {
			totalRestTime += subsequentRestDuration;
		}
	}

	double totalTimeWithRest = travelTime + totalRestTime;
	if (totalTimeWithRest - totalRestTime >= travelTime) {
		totalRestTime -= subsequentRestDuration;  
	}

	return travelTime + totalRestTime;
}