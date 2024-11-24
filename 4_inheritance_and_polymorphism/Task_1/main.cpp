#include <iostream>

using namespace std;


class Figure {
private:
	int numSides{};
	string name{};
protected:
	Figure(int numSides, string name) {
		this->name = name;
		this->numSides = numSides;
	}
public:
	Figure() : Figure(0, "������") {}


	string getName() const {
		return name;
	}

	int getNumSides() const {
		return numSides;
	}
};


class Triagle: public Figure {
public:
	Triagle() : Figure(3, "�����������") {}
};


class Quadrilateral: public Figure {
public:
	Quadrilateral(): Figure(4, "���������������") {}
};


int main() {
	setlocale(LC_ALL, "rus");

	Figure figure{};
	Triagle triagle{};
	Quadrilateral quadrilateral{};

	cout << "���������� ������:" << endl;
	cout << figure.getName() << ": " << figure.getNumSides() << endl;
	cout << triagle.getName() << ": " << triagle.getNumSides() << endl;
	cout << quadrilateral.getName() << ": " << quadrilateral.getNumSides() << endl;
}