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
	Figure() : Figure(0, "Фигура") {}


	string getName() const {
		return name;
	}

	int getNumSides() const {
		return numSides;
	}

	virtual void printInfo() const = 0;
};


class Triagle : public Figure {
private:
	int a{}, b{}, c{}, A{}, B{}, C{};
public:
	Triagle(int a, int b, int c, int A, int B, int C, string name = "Треугольник")
		: Figure(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {}

	void printInfo() const override {
		cout << this->getName() << ":" << endl;
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
	}
};


class RightTriangle : public Triagle {
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triagle(a, b, c, A, B, 90, "Прямоугольный треугольник") {};
};


class IsoscelesTriangle : public Triagle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triagle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
};


class EquilateralTriangle : public Triagle {
public:
	EquilateralTriangle(int a)
		: Triagle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {}
};


class Quadrilateral : public Figure {
private:
	int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, string name = "Четырёхугольник")
		: Figure(4, name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

	void printInfo() const override {
		cout << this->getName() << ":" << endl;
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c  << " d=" << d << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
	}
};


class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B, string name = "Параллелограмм")
		: Quadrilateral(a, b, a, b, A, B, A, B, name) {}
};


class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b, string name = "Прямоугольник"):
		Parallelogram(a, b, 90, 90, name) {}
};


class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B)
		: Parallelogram(a, a, A, B, "Ромб") {}
};


class Square : public Rectangle {
public:
	Square(int a):
		Rectangle(a, a, "Квадрат") {}
};


static void printInfo(Figure* figure) {
	figure->printInfo();
	cout << endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	Triagle triagle{ 10, 20, 30, 50, 60, 70 };
	RightTriangle rightTriangle{ 10, 20, 30, 50, 60 };
	IsoscelesTriangle isoscelesTriangle{ 10, 20, 50, 60 };
	EquilateralTriangle equilateralTriangle{ 30 };

	Quadrilateral quadrilateral{ 10, 20, 30, 40, 50, 60, 70, 80 };
	Rectangle rectangle{ 10,20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20, 30, 30, 40 };
	Rhombus rhombus{ 30, 30, 40 };

	printInfo(&triagle);
	printInfo(&rightTriangle);
	printInfo(&isoscelesTriangle);
	printInfo(&equilateralTriangle);

	printInfo(&quadrilateral);
	printInfo(&rectangle);
	printInfo(&square);
	printInfo(&parallelogram);
	printInfo(&rhombus);
}