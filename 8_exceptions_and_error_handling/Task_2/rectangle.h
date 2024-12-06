#pragma once
#include "parallelogram.h"


class Rectangle : public Quadrilateral {
public:
	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D,
		std::string name = "Прямоугольник");
};