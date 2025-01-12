#pragma once

#include <vector>
#include <iostream>

#include "Vehicle.h"


class Race {
protected:
	long distance{};
	std::vector<std::shared_ptr<Vehicle>> participants;
	RaceType typeRace{};
	std::vector<std::pair<std::string, double>> results{};

public:
	Race(long distance, RaceType typeRace);

	~Race() = default;

	int getNumberOfParticipants();

	RaceType getRaceType();

	long getDistance();

	bool isAlreadyRegistered(std::shared_ptr<Vehicle> vehicle);

	std::vector<std::shared_ptr<Vehicle>>& getRegisteredVehicles();

	void startRace();

	virtual bool registerVehicle(std::shared_ptr<Vehicle> vehicle) = 0;

	virtual std::string getRaceInfo() = 0;
};