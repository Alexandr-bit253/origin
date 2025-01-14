#include "Vehicle.h"


Vehicle::Vehicle(VehicleType typeVehicle) : typeVehicle(typeVehicle) {}


VehicleType Vehicle::getTypeVehicle() {
	return typeVehicle;
}