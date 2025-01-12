#include "MixedRace.h"


MixedRace::MixedRace(long distance) : Race(distance, MIXED) {}


std::string MixedRace::getRaceInfo() {
	std::string info{ "����� ��� ��������� � ���������� ����������. ����������: " + static_cast<int>(distance) };
	return info;
}


bool MixedRace::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
	if (isAlreadyRegistered(vehicle)) {
		throw std::runtime_error(vehicle->getName() + " ��� ���������������!");
	}

	participants.push_back(vehicle);
	return true;
}