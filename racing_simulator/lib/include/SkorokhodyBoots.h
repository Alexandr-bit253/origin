#pragma once

#include "GroundVehicle.h"


class SkorokhodyBoots : public GroundVehicle {
public:
	SkorokhodyBoots(std::string name, double speed);

	double calculateRaceTime(double distance) const;
};