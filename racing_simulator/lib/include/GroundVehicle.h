#pragma once

#include <vector>

#include "Vehicle.h"


class GroundVehicle : public Vehicle {
private:
	std::string name{};
	double speed{};
	double timeUntilRest{};
	std::vector<double> restDuration{};
	VehicleType typeVehicle{ GROUND_VEHICLE };

public:
	GroundVehicle(std::string name, double speed, double timeUntilRest, std::vector<double> restDuration);

	std::string getName() override;

	VehicleType getTypeVehicle() override;

	double calculateRaceTime(double distance) const override;
};