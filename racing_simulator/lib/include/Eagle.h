#pragma once

#include "AirVehicle.h"


class Eagle : public AirVehicle {
public:
	Eagle(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};