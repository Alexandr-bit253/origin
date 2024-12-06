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
	
	std::cout << "Введите первое число: ";
	std::cin >> num1;

	std::cout << "Введите второе число: ";
	std::cin >> num2;

	std::cout <<
		"Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;

	switch (Operations(operation))
	{
	case Operations::ADD:
		std::cout << num1 << " прибавить " << num2 << " = " << mAdd(num1, num2) << std::endl;
		break;
	case Operations::SUB:
		std::cout << num1 << " вычесть " << num2 << " = " << mSub(num1, num2) << std::endl;
		break;
	case Operations::MULT:
		std::cout << num1 << " умножить на " << num2 << " = " << mMult(num1, num2) << std::endl;
		break;
	case Operations::DIV:
		std::cout << num1 << " разделить на " << num2 << " = " << mDiv(num1, num2) << std::endl;
		break;
	case Operations::POW:
		std::cout << num1 << " в степени " << num2 << " = " << mPow(num1, num2) << std::endl;
		break;
	default:
		break;
	}
}