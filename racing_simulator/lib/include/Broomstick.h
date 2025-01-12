#pragma once

#include "AirVehicle.h"


class Broomstick : public AirVehicle {
public:
	Broomstick( std::string name,double speed);

	double calculateRaceTime(double distance) const;
};