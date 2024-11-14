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

	cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	cin >> user_input;

	if (user_input == "��") {
		cout << "������� ��������� �������� ��������: ";
		cin >> initial_value;
		count = Counter(initial_value);
	}

	while (true) {
		cout << "������� �������('+', '-', '=' ��� 'x') : ";
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
		else if (user_input != "x" || user_input != "�") {
			break;
		}
		else {
			cout << "������������ ��������. ���������� ���." << endl;
		}
	}
	cout << "�� ��������!" << endl;
}