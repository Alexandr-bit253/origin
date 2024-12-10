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

	virtual bool isCorrect() const {
		return true;
	}

	virtual void printInfo() const {
		cout << name << ":" << endl;
		cout << (isCorrect() ? "Правильная" : "Неправильная") << endl;
		cout << "Количество сторон: " << numSides << endl;
	};
};


class Triagle : public Figure {
protected:
	int a{}, b{}, c{}, A{}, B{}, C{};
public:
	Triagle(int a, int b, int c, int A, int B, int C, string name = "Треугольник")
		: Figure(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {
	}

	bool isCorrect() const override {
		return (A + B + C == 180);
	}

	void printInfo() const override {
		Figure::printInfo();
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
	}
};


class RightTriangle : public Triagle {
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triagle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
	};

	bool isCorrect() const override {
		return Triagle::isCorrect() && (A + B == 90);
	}
};


class IsoscelesTriangle : public Triagle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triagle(a, b, a, A, B, A, "Равнобедренный треугольник") {
	}

	bool isCorrect() const override {
		return Triagle::isCorrect() && (A == C);
	}
};


class EquilateralTriangle : public Triagle {
public:
	EquilateralTriangle(int a)
		: Triagle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
	}

	bool isCorrect() const override {
		return Triagle::isCorrect() && (a == c && c == b);
	}
};


class Quadrilateral : public Figure {
private:
	int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, string name = "Четырёхугольник")
		: Figure(4, name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
	}

	bool isCorrect() const override {
		return (A + B + C + D == 360);
	}

	void printInfo() const override {
		Figure::printInfo();
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
	}
};


class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B, string name = "Параллелограмм")
		: Quadrilateral(a, b, a, b, A, B, A, B, name) {
	}

	bool isCorrect() const override {
		return Quadrilateral::isCorrect();
	}
};


class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b, string name = "Прямоугольник") :
		Parallelogram(a, b, 90, 90, name) {
	}

	bool isCorrect() const override {
		return Quadrilateral::isCorrect();
	}
};


class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B)
		: Parallelogram(a, a, A, B, "Ромб") {
	}

	bool isCorrect() const override {
		return Quadrilateral::isCorrect();
	}
};


class Square : public Rectangle {
public:
	Square(int a) :
		Rectangle(a, a, "Квадрат") {
	}

	bool isCorrect() const override {
		return Quadrilateral::isCorrect();
	}
};


static void printInfo(Figure* figure) {
	figure->printInfo();
	cout << endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	Figure figure{};

	Triagle triagle{ 10, 20, 30, 50, 60, 70 };
	RightTriangle rightTriangle1{ 10, 20, 30, 50, 60 };
	RightTriangle rightTriangle2{ 10, 20, 30, 50, 40 };
	IsoscelesTriangle isoscelesTriangle{ 10, 20, 50, 60 };
	EquilateralTriangle equilateralTriangle{ 30 };

	Quadrilateral quadrilateral{ 10, 20, 30, 40, 50, 60, 70, 80 };
	Rectangle rectangle{ 10,20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20, 30, 30, 40 };
	Rhombus rhombus{ 30, 30, 40 };

	printInfo(&figure);
	printInfo(&triagle);
	printInfo(&rightTriangle1);
	printInfo(&rightTriangle2);
	printInfo(&isoscelesTriangle);
	printInfo(&equilateralTriangle);
	
	printInfo(&quadrilateral);
	printInfo(&rectangle);
	printInfo(&square);
	printInfo(&parallelogram);
	printInfo(&rhombus);
}