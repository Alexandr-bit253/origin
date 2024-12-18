#include <iostream>

#include "Greeter.h"


int main() {
	system("chcp 1251");

	Greeter::Greeter greeter;
	std::string name{};
	
	std::cout << "¬ведите им€: ";
	std::cin >> name;

	greeter.hello(name);
}