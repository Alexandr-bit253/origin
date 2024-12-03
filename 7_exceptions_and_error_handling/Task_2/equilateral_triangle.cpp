#pragma once
#include "equilateral_triangle.h"
#include "error_creating_shape.h"


EquilateralTriangle::EquilateralTriangle(int a, int b, int c, int A, int B, int C)
	: Triangle(a, b, c, A, B, C, "�������������� �����������") {
	if (a != b || b != c || a != c) {
		throw ErrorCreatingShape("�� ��� ������� �����");
	}
	else if (A != 60 || B != 60 || C != 60) {
		throw ErrorCreatingShape("�� ��� ���� ����� 60");
	}
}