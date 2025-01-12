#pragma once

#include "GroundVehicle.h"


class Centaur : public GroundVehicle {
public:
	Centaur(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};