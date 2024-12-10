#pragma once

#include "figure.h"


class Quadrilateral : public Figure {
private:
	int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, 
		std::string name = "Четырёхугольник");

	void printInfo() const override;
};