#include "geometricFigureDll.h"


Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name)
	: Figure(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {}


void Triangle::printInfo() const {
	std::cout << this->getName() << ":" << std::endl;
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
}