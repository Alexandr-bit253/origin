#include <iostream>
#include "Counter.h"


int main() {
	system("chcp 1251");

	std::string user_input{};
	int initial_value{};
	Counter count;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> user_input;

	if (user_input == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> initial_value;
		count = Counter(initial_value);
	}

	while (true) {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
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
		else if (user_input == "x" || user_input == "х") {
			std::cout << "До свидания!" << std::endl;
			break;
		}
		else {
			std::cout << "Некорректное значение. Поробуйте еще раз.\n";
		}
	}
}