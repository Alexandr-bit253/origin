#include <iostream>

#include "Leaver.h"


int main() {
	system("chcp 1251");

	Leaver::Leaver leaver{};
	std::string name{};

	std::cout << "¬ведите им€: ";
	std::cin >> name;
	leaver.leave(name);
}