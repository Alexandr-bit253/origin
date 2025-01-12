#include "MixedRace.h"


MixedRace::MixedRace(long distance) : Race(distance, MIXED) {}


std::string MixedRace::getRaceInfo() {
	std::string info{ "Гонка для наземного и воздушного транспорта. Расстояние: " + static_cast<int>(distance) };
	return info;
}


bool MixedRace::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
	if (isAlreadyRegistered(vehicle)) {
		throw std::runtime_error(vehicle->getName() + " уже зарегистрирован!");
	}

	participants.push_back(vehicle);
	return true;
}