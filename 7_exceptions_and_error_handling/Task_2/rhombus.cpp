#pragma once

#include "rhombus.h"
#include "error_creating_shape.h"


Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D)
	: Parallelogram(a, b, c, d, A, B, C, D, "Ромб") {
	if (a != b || b != c || c != d || d != a) {
		throw ErrorCreatingShape("не все стороны равны");
	}
}