#include <iostream>

using namespace std;


class Calculator {
private:
	double num1{}, num2{};
public:
	bool set_num1(const double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		return false;
	}

	bool set_num2(const double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		return false;
	}

	double add() const {
		return num1 + num2;
	}

	double multiply() const {
		return num1 * num2;
	}

	double subtract_1_2() const {
		return num1 - num2;
	}

	double subtract_2_1() const {
		return num2 - num1;
	}

	double divide_1_2() const {
		return num1 / num2;
	}

	double divide_2_1() const {
		return num2 / num1;
	}
};


void print_calc(const Calculator* calc) {
	cout << "num1 + num2 = " << calc->add() << endl;
	cout << "num1 - num2 = " << calc->subtract_1_2() << endl;
	cout << "num2 - num1 = " << calc->subtract_2_1() << endl;
	cout << "num1 * num2 = " << calc->multiply() << endl;
	cout << "num1 / num2 = " << calc->divide_1_2() << endl;
	cout << "num2 / num1 = " << calc->divide_2_1() << endl;
}


enum class Numbers {
	NUM_1,
	NUM_2,
};


void read_num(Numbers name, Calculator* calc) {
	switch (name)
	{
	case Numbers::NUM_1: 
		{
			double num1{};
			while (true) {
				cout << "Введите num1: ";
				cin >> num1;
				if (calc->set_num1(num1)) {
					break;
				}
				else {
					cout << "Неверный ввод!\n";
				}
			}
			break; 
		}
	case Numbers::NUM_2: 
		{
			double num2{};
			while (true) {
				cout << "Введите num2: ";
				cin >> num2;
				if (calc->set_num2(num2)) {
					break;
				}
				else {
					cout << "Неверный ввод!\n";
				}
			}
			break;
		}
	}
	
}


int main() {
	setlocale(LC_ALL, "rus");

	Calculator calc;

	while (true) {
		read_num(Numbers::NUM_1, &calc);
		read_num(Numbers::NUM_2, &calc);
		print_calc(&calc);
	}
}