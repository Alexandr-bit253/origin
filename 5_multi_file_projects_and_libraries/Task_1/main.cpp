#include <iostream>

#include "operations.h"


enum class Operations
{
	ADD = 1,
	SUB,
	MULT,
	DIV,
	POW
};


int main() {
	setlocale(LC_ALL, "rus");

	int num1{}, num2{}, operation{};
	
	std::cout << "������� ������ �����: ";
	std::cin >> num1;

	std::cout << "������� ������ �����: ";
	std::cin >> num2;

	std::cout <<
		"�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
	std::cin >> operation;

	switch (Operations(operation))
	{
	case Operations::ADD:
		std::cout << num1 << " ��������� " << num2 << " = " << mAdd(num1, num2) << std::endl;
		break;
	case Operations::SUB:
		std::cout << num1 << " ������� " << num2 << " = " << mSub(num1, num2) << std::endl;
		break;
	case Operations::MULT:
		std::cout << num1 << " �������� �� " << num2 << " = " << mMult(num1, num2) << std::endl;
		break;
	case Operations::DIV:
		std::cout << num1 << " ��������� �� " << num2 << " = " << mDiv(num1, num2) << std::endl;
		break;
	case Operations::POW:
		std::cout << num1 << " � ������� " << num2 << " = " << mPow(num1, num2) << std::endl;
		break;
	default:
		break;
	}
}