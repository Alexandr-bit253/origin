#pragma once

#include "figure.h"


class Triangle : public Figure {
private:
	int a{}, b{}, c{}, A{}, B{}, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C, std::string name = "Треугольник");

	void printInfo() const override;
};