#pragma once


enum RaceType {
	GROUND = 1,
	AIR,
	MIXED
};


enum VehicleType {
	GROUND_VEHICLE,
	AIR_VEHICLE,
};


 void printHello();

 bool choosingTypeOfRace(RaceType* typeRace);

 bool getDistance(long* distance);