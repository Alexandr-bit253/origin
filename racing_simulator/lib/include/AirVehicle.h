#pragma once

#include <vector>

#include "Vehicle.h"


class AirVehicle : public Vehicle {
private:
	std::string name{};
	double speed{};
	VehicleType typeVehicle{ AIR_VEHICLE };

public:
	AirVehicle(std::string name, double speed);

	std::string getName() override;

	VehicleType getTypeVehicle() override;

	double calculateRaceTime(double distance) const override;
};