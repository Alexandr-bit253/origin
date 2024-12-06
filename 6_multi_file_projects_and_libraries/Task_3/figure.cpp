#include "figure.h"


Figure::Figure(int numSides, std::string name) {
	this->name = name;
	this->numSides = numSides;
}


Figure::Figure() : Figure(0, "Фигура") {}


std::string Figure::getName() const {
	return name;
}


int Figure::getNumSides() const {
	return numSides;
}