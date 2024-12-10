#include "triangle.h"
#include "error_creating_shape.h"


Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name)
	: Figure(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {
	if (A + B + C != 180) {
		throw ErrorCreatingShape("����� ����� �� ����� 180");
	}
}


void Triangle::printInfo() const {
	std::cout << this->getName() << " (������� " << a << ", " << b << ", " << c << "; ���� "
		<< A << ", " << B << ", " << C << ") ������" << std::endl;
}