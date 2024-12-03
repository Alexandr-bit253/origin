#pragma once
#include "rectangle.h"
#include "error_creating_shape.h"


Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D,
	std::string name) :
	Quadrilateral(a, b, c, d, A, B, C, D, name) {
	if (a != c && b != d) {
		throw ErrorCreatingShape("стороны a,c и b,d попарно не равны");
	}
	else if (A != 90 || B != 90 || C != 90 || D != 90) {
		throw ErrorCreatingShape("не все углы равны 90");
	}
}