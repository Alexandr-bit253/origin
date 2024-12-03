#pragma once
#include "isosceles_triangle.h"
#include "error_creating_shape.h"


IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
	: Triangle(a, b, c, A, B, C, "Равнобедренный треугольник") {
	if (a != c) {
		throw ErrorCreatingShape("стороны a и c не равны");
	}
	else if (A != C) {
		throw ErrorCreatingShape("углы A и C не равны");
	}
}