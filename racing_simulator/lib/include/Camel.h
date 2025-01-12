#pragma once

#include "GroundVehicle.h"


class Camel : public GroundVehicle {
private:
	double speed{ 10 };
	double timeUntilRest{ 30 };
	double firstRestDuration{ 5 };
	double subsequentRestDuration{ 8 };

public:
	Camel(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};