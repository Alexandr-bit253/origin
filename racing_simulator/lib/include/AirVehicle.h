#pragma once

#include <vector>

#include "Vehicle.h"


class AirVehicle : public Vehicle {
private:
	std::string name{};
	double speed{};
	std::vector<double> restDuration{};
	VehicleType typeVehicle{ AIR_VEHICLE };

public:
	AirVehicle(std::string name, double speed, std::vector<double> restDuration);

	std::string getName() override;

	double calculateRaceTime(double distance) const override;
};