#pragma once

#include <string>

#include "utilsDll.h"


class Vehicle {
private:
	VehicleType typeVehicle;

public:
	Vehicle(VehicleType type);

	~Vehicle() = default;

	virtual std::string getName() = 0;

	VehicleType getTypeVehicle();

	virtual double calculateRaceTime(double distance) const = 0;
};