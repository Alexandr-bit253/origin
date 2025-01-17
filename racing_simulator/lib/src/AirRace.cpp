#pragma once

#include <stdexcept>

#include "AirRace.h"


AirRace::AirRace(long distance) : Race(distance, AIR) {}


std::string AirRace::getRaceInfo() {
	std::string info{ "Гонка для воздушного транспорта. Расстояние: " + static_cast<int>(distance) };
	return info;
}


bool AirRace::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
	if (vehicle->getTypeVehicle() != VehicleType::AIR_VEHICLE) {
		throw std::invalid_argument("Попытка зарегистрировать неправильный тип транспортного средства!");
	} 

	if (isAlreadyRegistered(vehicle)) {
		throw std::runtime_error(vehicle->getName() + " уже зарегистрирован!");
	}

	participants.push_back(vehicle);
	return true;
}