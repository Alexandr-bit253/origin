#include <iostream>

#include "utilsDll.h"


void printHello() {
    std::cout << "Hello world!" << std::endl;
}


bool choosingTypeOfRace(RaceType* typeRace) {
	int choice{};

	std::cout << "1. Гонка для наземного транспорта." << std::endl;
	std::cout << "2. Гонка для воздушного транспорта." << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта." << std::endl;
	std::cout << "Выберите тип гонки: ";

	std::cin >> choice;

	if (choice < 1 || choice > 3) {
		std::cout << "Ошибка: Неверный выбор. Попробуйте снова." << std::endl;
		return false;
	}

	*typeRace = static_cast<RaceType>(choice);

	return true;
}


bool getDistance(long* distance) {
	int tempDistance{};

	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> tempDistance;

	if (tempDistance < 1) {
		std::cout << "Дистанция должна быть положительной. Поробуйте еше раз." << std::endl;
		return false;
	}

	*distance = tempDistance;

	return true;
}