#pragma once

#include "Race.h"


class GroundRace : public Race {
public:
	GroundRace(long distance);

	std::string getRaceInfo() override;

	bool registerVehicle(std::shared_ptr<Vehicle> vehicle) override;
};