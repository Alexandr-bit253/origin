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


void printError() {
    std::cout << "Вы ввели некорректное значение! Попробуйте еще раз." << std::endl;
    std::cout << std::endl;
}


bool choosingTypeOfRace(RaceType* typeRace) {
    int choice{};

    std::cout << "1. Гонка для наземного транспорта." << std::endl;
    std::cout << "2. Гонка для воздушного транспорта." << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта." << std::endl;
    std::cout << "Выберите тип гонки: ";

    std::cin >> choice;
    std::cout << std::endl;

    if (choice < 1 || choice > 3) {
        printError();
        return false;
    }

    *typeRace = static_cast<RaceType>(choice);

    return true;
}


bool getDistance(long* distance) {
    int tempDistance{};

    std::cout << "Укажите длину дистанции (должна быть положительна): ";
    std::cin >> tempDistance;
    std::cout << std::endl;

    if (tempDistance < 1) {
        std::cout << "Дистанция должна быть положительной. Попробуйте еше раз." << std::endl;
        std::cout << std::endl;
        return false;
    }

    *distance = tempDistance;

    return true;
}


void printVehicles() {
    std::vector<std::string> vehicles{
        "",
        "Ботинки-вездеходы",
        "Метла",
        "Верблюд",
        "Кентавр",
        "Орёл",
        "Верблюд-быстроход",
        "Ковёр-самолет",
    };

    for (size_t i = 1; i < vehicles.size(); i++) {
        std::cout << i << ". " << vehicles[i] << std::endl;
    }
}


void printRaceInfo(std::shared_ptr<Race> race) {
    switch (race->getRaceType())
    {
    case(GROUND):
        std::cout << "Гонка для наземного транспорта. Расстояние: ";
        break;
    case(AIR):
        std::cout << "Гонка для воздушного транспорта. Расстояние: ";
        break;
    case(MIXED):
        std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: ";
        break;
    default:
        break;
    }

    std::cout << race->getDistance() << std::endl;
}


void printRaceParticipants(std::shared_ptr<Race> race) {
    std::cout << "Зарегистрированные транспортные средства: ";
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

        printRaceInfo(race);

        if (race->getNumberOfParticipants() > 0) {
            printRaceParticipants(race);
        }

        printVehicles();

        std::cout << "0. Закончить регистрацию" << std::endl;
        std::cout << "Выберите транспорт или 0 для окончания процесса ренистрации: ";
        std::cin >> choice;
        std::cout << std::endl;

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
            printError();
            continue;
        }

        try
        {
            race->registerVehicle(vehicle);
            std::cout << std::endl;
            std::cout << vehicle->getName() << " успешно зарегистрирован!" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}


void startRace(std::shared_ptr<Race> race) {
    int count{ 1 };
    const auto results = race->startRace();

    std::cout << std::endl;
    std::cout << "Результаты гонки: " << std::endl;

    for (const auto& [name, time] : race->startRace()) {
        std::cout << count << ". " << name << ". Время: " << time << std::endl;
        ++count;
    }

    race->clearParticipants();

    std::cout << std::endl;
}


int main() {
    system("chcp 1251");

    RaceType racingType{};
    std::shared_ptr<Race> race{ nullptr };
    long distance{};

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

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
            if (race->getNumberOfParticipants() < 2) {
                std::cout << "Должно быть зарегистрированно хотябы 2 транспортных средства" << std::endl;
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
                std::cout << "Выберите действие: ";
                std::cin >> action;
                std::cout << std::endl;

                if (action == 1) {
                    vehicleRegistration(race);
                }
                else {
                    printError();
                    continue;
                }

            }
            else {
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
                std::cout << "2. Начать гонку" << std::endl;
                std::cout << "Выберите действие: ";
                std::cin >> action;
                std::cout << std::endl;

                if (action == 1) {
                    vehicleRegistration(race);
                    continue;
                }
                else if(action == 2) {
                    startRace(race);
                }
                else {
                    printError();
                    continue;
                }

                while (true) {
                    std::cout << "1. Провести еще одну гонку" << std::endl;
                    std::cout << "2. Выйти" << std::endl;
                    std::cout << "Выберите действие: ";
                    std::cin >> action;
                    std::cout << std::endl;

                    if (action == 1) {
                        break;
                    }
                    else if (action == 2) {
                        return 0;
                    }
                    else {
                        printError();
                        continue;
                    }
                }
                break;
            }
        }

       continue;
    }
}