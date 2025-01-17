#include "GroundRace.h"


GroundRace::GroundRace(long distance) : Race(distance, GROUND) {}


std::string GroundRace::getRaceInfo() {
	std::string info{ "Гонка для наземного транспорта. Расстояние: " + static_cast<int>(distance) };
	return info;
}


bool GroundRace::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
	if (vehicle->getTypeVehicle() != VehicleType::GROUND_VEHICLE) {
		throw std::invalid_argument("Попытка зарегистрировать неправильный тип транспортного средства!");
	}

	if (isAlreadyRegistered(vehicle)) {
		throw std::runtime_error(vehicle->getName() + " уже зарегистрирован!");
	}

	participants.push_back(vehicle);
	return true;
}