#pragma once

#include <string>

#include "utilsDll.h"


class Vehicle {
private:
	std::string name{};
	double speed;
	VehicleType typeVehicle;

public:
	Vehicle(std::string name, double speed, VehicleType type);

	~Vehicle() = default;

	std::string getName();

	double getSpeed() const;

	VehicleType getTypeVehicle();

	virtual double calculateRaceTime(double distance) const = 0;
};