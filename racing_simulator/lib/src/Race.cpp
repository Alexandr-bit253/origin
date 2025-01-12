#include <iostream>

#include "Race.h"


Race::Race(long distance, RaceType typeRace) : distance(distance), typeRace(typeRace){}


int Race::getNumberOfParticipants() {
	return participants.size();
}


RaceType Race::getRaceType() {
	return typeRace;
}


long Race::getDistance() {
	return distance;
}


std::vector<std::shared_ptr<Vehicle>>& Race::getRegisteredVehicles() {
	return participants;
}


bool Race::isAlreadyRegistered(std::shared_ptr<Vehicle> vehicle) {
	if (participants.size() != 0) {
		for (const auto& participant : participants) {
			if (participant->getName() == vehicle->getName()) {
				return true;
			}
		}
	}
	return false;
}


void Race::startRace() {
	for (const auto& vehicle : participants) {
		double raceTime = vehicle->calculateRaceTime(distance);
		results.emplace_back(vehicle->getName(), raceTime);
	}
}