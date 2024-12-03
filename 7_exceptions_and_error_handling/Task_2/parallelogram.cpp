#pragma once
#include "parallelogram.h"
#include "error_creating_shape.h"


Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D,
	std::string name)
	: Quadrilateral(a, b, c, d, A, B, C, D, name) {
	if (a != c && b != d) {
		throw ErrorCreatingShape("стороны a,c и b,d попарно не равны");
	}
	else if (A != C && B != D) {
		throw ErrorCreatingShape("углы A,C и B,D попарно не равны");
	}
}