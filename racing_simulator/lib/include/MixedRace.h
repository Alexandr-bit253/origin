#pragma once

#include "Race.h"


class MixedRace : public Race {
public:
	MixedRace(long distance);

	std::string getRaceInfo() override;

	bool registerVehicle(std::shared_ptr<Vehicle> vehicle) override;
};