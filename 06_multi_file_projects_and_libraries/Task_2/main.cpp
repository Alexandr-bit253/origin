#include <iostream>
#include "Counter.h"


int main() {
	system("chcp 1251");

	std::string user_input{};
	int initial_value{};
	Counter count;

	std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	std::cin >> user_input;

	if (user_input == "��") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> initial_value;
		count = Counter(initial_value);
	}

	while (true) {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> user_input;

		if (user_input == "+") {
			count.increment();
		}
		else if (user_input == "-") {
			count.decrement();
		}
		else if (user_input == "=") {
			std::cout << count.get_value() << std::endl;
		}
		else if (user_input == "x" || user_input == "�") {
			std::cout << "�� ��������!" << std::endl;
			break;
		}
		else {
			std::cout << "������������ ��������. ��������� ��� ���.\n";
		}
	}
}