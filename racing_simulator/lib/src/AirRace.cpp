#pragma once

#include <stdexcept>

#include "AirRace.h"


AirRace::AirRace(long distance) : Race(distance, AIR) {}


std::string AirRace::getRaceInfo() {
	std::string info{ "����� ��� ���������� ����������. ����������: " + static_cast<int>(distance) };
	return info;
}


bool AirRace::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
	if (vehicle->getTypeVehicle() != VehicleType::AIR_VEHICLE) {
		throw std::invalid_argument("������� ���������������� ������������ ��� ������������� ��������!");
	} 

	if (isAlreadyRegistered(vehicle)) {
		throw std::runtime_error(vehicle->getName() + " ��� ���������������!");
	}

	participants.push_back(vehicle);
	return true;
}