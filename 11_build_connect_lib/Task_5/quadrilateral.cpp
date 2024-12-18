#include "geometricFigureDll.h"


Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, 
	std::string name)
	: Figure(4, name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
}


void Quadrilateral::printInfo() const {
	std::cout << this->getName() << ":" << std::endl;
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}