#include <iostream>
#include "leaver.h"

int main() {
    Leaver leaver;
    std::string name;

    std::cout << "Введите имя: ";
    std::cin >> name;

    std::cout << leaver.leave(name) << std::endl;

    return 0;
}
