#include <iostream>


#define MODE 1

#ifndef MODE
#error ���������� ���������� MODE
#endif

#if MODE == 1
int add(int a, int b) {
	return a + b;
}
#endif

int main() {
	setlocale(LC_ALL, "rus");

#if MODE == 0
	std::cout << "������� � ������ ����������" << std::endl;

#elif MODE == 1
	std::cout << "������� � ������ ������" << std::endl;
	int num1{}, num2{};
	std::cout << "������� ����� 1: ";
	std::cin >> num1;
	std::cout << "������� ����� 2: ";
	std::cin >> num2;
	std::cout << "��������� ��������: " << add(num1, num2) << std::endl;

#else
	std::cout << "����������� �����. ���������� ������" << std::endl;
#endif
}