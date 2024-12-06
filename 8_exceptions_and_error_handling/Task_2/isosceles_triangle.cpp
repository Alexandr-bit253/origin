#pragma once
#include "isosceles_triangle.h"
#include "error_creating_shape.h"


IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
	: Triangle(a, b, c, A, B, C, "�������������� �����������") {
	if (a != c) {
		throw ErrorCreatingShape("������� a � c �� �����");
	}
	else if (A != C) {
		throw ErrorCreatingShape("���� A � C �� �����");
	}
}