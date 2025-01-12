#include <iostream>

#include "utilsDll.h"


void printHello() {
    std::cout << "Hello world!" << std::endl;
}


bool choosingTypeOfRace(RaceType* typeRace) {
	int choice{};

	std::cout << "1. ����� ��� ��������� ����������." << std::endl;
	std::cout << "2. ����� ��� ���������� ����������." << std::endl;
	std::cout << "3. ����� ��� ��������� � ���������� ����������." << std::endl;
	std::cout << "�������� ��� �����: ";

	std::cin >> choice;

	if (choice < 1 || choice > 3) {
		std::cout << "������: �������� �����. ���������� �����." << std::endl;
		return false;
	}

	*typeRace = static_cast<RaceType>(choice);

	return true;
}


bool getDistance(long* distance) {
	int tempDistance{};

	std::cout << "������� ����� ��������� (������ ���� ������������): ";
	std::cin >> tempDistance;

	if (tempDistance < 1) {
		std::cout << "��������� ������ ���� �������������. ��������� ��� ���." << std::endl;
		return false;
	}

	*distance = tempDistance;

	return true;
}