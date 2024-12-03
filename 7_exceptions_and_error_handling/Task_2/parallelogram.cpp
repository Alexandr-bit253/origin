#pragma once
#include "parallelogram.h"
#include "error_creating_shape.h"


Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D,
	std::string name)
	: Quadrilateral(a, b, c, d, A, B, C, D, name) {
	if (a != c && b != d) {
		throw ErrorCreatingShape("������� a,c � b,d ������� �� �����");
	}
	else if (A != C && B != D) {
		throw ErrorCreatingShape("���� A,C � B,D ������� �� �����");
	}
}