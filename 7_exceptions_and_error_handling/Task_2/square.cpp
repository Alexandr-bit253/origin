#pragma once

#include "square.h"
#include "error_creating_shape.h"


Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) :
	Rectangle(a, b, c, d, A, B, C, D, " вадрат") {
	if (a != b || b != c || c != d || d != a) {
		throw ErrorCreatingShape("не все стороны равны");
	}
}