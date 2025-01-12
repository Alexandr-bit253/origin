#pragma once

#include "GroundVehicle.h"


class FastCamel : public GroundVehicle {
public:
	FastCamel(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};