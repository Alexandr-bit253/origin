#pragma once

#include "AirVehicle.h"


class MagicCarpet : public AirVehicle {
public:
	MagicCarpet(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};