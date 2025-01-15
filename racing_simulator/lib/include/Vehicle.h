#pragma once

#include <string>

#include "utilsDll.h"


class Vehicle {
private:
	VehicleType typeVehicle;

public:
	Vehicle();

	~Vehicle() = default;

	virtual std::string getName() = 0;

	virtual VehicleType getTypeVehicle() = 0;

	virtual double calculateRaceTime(double distance) const = 0;
};