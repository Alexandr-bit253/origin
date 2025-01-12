#pragma once

#include "Race.h"


class AirRace : public Race {
public:
	AirRace(long distance);

	std::string getRaceInfo() override;

	bool registerVehicle(std::shared_ptr<Vehicle> vehicle) override;
};