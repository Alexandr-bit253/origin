#include <iostream>

#include "Leaver.h"


int main() {
	system("chcp 1251");

	Leaver::Leaver leaver{};
	std::string name{};

	std::cout << "������� ���: ";
	std::cin >> name;
	leaver.leave(name);
}