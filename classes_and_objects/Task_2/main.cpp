#include <iostream>

using namespace std;


class Counter {
private:
	int value;

public:
	Counter(int initial_value = 1) : value(initial_value) {}

	void increment() {
		++value;
	}

	void decrement() {
		--value;
	}

	int get_value() {
		return value;
	}
};


int main() {
	system("chcp 1251");

	string user_input{};
	int initial_value{};
	Counter count;

	cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	cin >> user_input;

	if (user_input == "да") {
		cout << "Введите начальное значение счётчика: ";
		cin >> initial_value;
		count = Counter(initial_value);
	}

	while (true) {
		cout << "Введите команду('+', '-', '=' или 'x') : ";
		cin >> user_input;

		if (user_input == "+") {
			count.increment();
		}
		else if (user_input == "-") {
			count.decrement();
		}
		else if (user_input == "=") {
			cout << count.get_value() << endl;
			continue;
		}
		else if (user_input != "x" || user_input != "х") {
			break;
		}
		else {
			cout << "Неправильная комманда. Попробуйте еще." << endl;
		}
	}
	cout << "До свидания!" << endl;
}