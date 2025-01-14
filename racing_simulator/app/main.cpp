#include <iostream>

#include "utilsDll.h"
#include "GroundRace.h"
#include "AirRace.h"
#include "MixedRace.h"
#include "SkorokhodyBoots.h"
#include "Broomstick.h"
#include "Camel.h" 
#include "Centaur.h"
#include "Eagle.h"
#include "FastCamel.h"
#include "MagicCarpet.h"


void printVehicles() {
    std::vector<std::string> vehicles{
        "",
        "�������-���������",
        "�����",
        "�������",
        "�������",
        "���",
        "�������-���������",
        "����-�������",
    };

    for (size_t i = 1; i < vehicles.size(); i++) {
        std::cout << i << ". " << vehicles[i] << std::endl;
    }
}


void printRaceInfo(std::shared_ptr<Race> race) {
    switch (race->getRaceType())
    {
    case(GROUND):
        std::cout << "����� ��� ��������� ����������. ����������: ";
        break;
    case(AIR):
        std::cout << "����� ��� ���������� ����������. ����������: ";
        break;
    case(MIXED):
        std::cout << "����� ��� ��������� � ���������� ����������. ����������: ";
        break;
    default:
        break;
    }

    std::cout << race->getDistance() << std::endl;
}


void printRaceParticipants(std::shared_ptr<Race> race) {
    std::cout << "������������������ ������������ ��������: ";
    const auto& registeredVehicles = race->getRegisteredVehicles();
    for (size_t i = 0; i < registeredVehicles.size(); ++i) {
        std::cout << registeredVehicles[i]->getName();
        if (i < registeredVehicles.size() - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << std::endl;
        }
    }
}


void vehicleRegistration(std::shared_ptr<Race> race) {
    while (true) {
        int choice{};
        std::shared_ptr<Vehicle> vehicle{ nullptr };

        std::cout << std::endl;

        printRaceInfo(race);

        if (race->getNumberOfParticipants() > 0) {
            printRaceParticipants(race);
        }

        printVehicles();

        std::cout << "0. ��������� �����������" << std::endl;
        std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice)
        {
        case(1):
            vehicle = std::make_shared<SkorokhodyBoots>();
            break;
        case(2):
            vehicle = std::make_shared<Broomstick>();
            break;
        case(3):
            vehicle = std::make_shared<Camel>();
            break;
        case(4):
            vehicle = std::make_shared<Centaur>();
            break;
        case(5):
            vehicle = std::make_shared<Eagle>();
            break;
        case(6):
            vehicle = std::make_shared<FastCamel>();
            break;
        case(7):
            vehicle = std::make_shared<MagicCarpet>();
            break;
        default:
            break;
        }

        try
        {
            race->registerVehicle(vehicle);
            std::cout << vehicle->getName() << " ������� ���������������!" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}


int main() {
    system("chcp 1251");

    RaceType racingType{};
    std::shared_ptr<Race> race{ nullptr };
    long distance{};

    std::cout << "����� ���������� � �������� ���������!" << std::endl;

    while (true) {
        while (!choosingTypeOfRace(&racingType)) { continue; }

        while (!getDistance(&distance)) { continue; }

        switch (racingType)
        {
        case GROUND:
            race = std::make_shared<GroundRace>(distance);
            break;
        case AIR:
            race = std::make_shared<AirRace>(distance);
            break;
        case MIXED:
            race = std::make_shared<MixedRace>(distance);
            break;
        default:
            break;
        }

        int action{};
        while (true) {
            std::cout << std::endl;
            if (race->getNumberOfParticipants() < 2) {
                std::cout << "������ ���� ����������������� ������ 2 ������������ ��������" << std::endl;
                std::cout << "1. ���������������� ���������" << std::endl;
                std::cout << "�������� ��������: ";
                std::cin >> action;

                if (action == 1) {
                    vehicleRegistration(race);
                }
                else {
                    continue;
                }

            }
            else {
                std::cout << "1. ���������������� ���������" << std::endl;
                std::cout << "2. ������ �����" << std::endl;
                std::cout << "�������� ��������: ";
                std::cin >> action;

                if (action == 1) {
                    vehicleRegistration(race);
                }
                else if(action == 2) {
                    race->startRace();
                }
                else {
                    continue;
                }
            }
        }

        break;
    }

    getchar();
}