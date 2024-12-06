#pragma once
#include "quadrilateral.h"
#include "error_creating_shape.h"


Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, 
	std::string name)
	: Figure(4, name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
	if (A + B + C + D != 360) {
		throw ErrorCreatingShape("сумма углов не равна 360");
	}
}


void Quadrilateral::printInfo() const {
	std::cout << this->getName() << " (стороны " << a << ", " << b << ", " << c << "; углы "
		<< A << ", " << B << ", " << C << ") создан" << std::endl;
}