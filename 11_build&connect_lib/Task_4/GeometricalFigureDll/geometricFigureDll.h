#pragma once

#include<iostream>

#ifdef GEOMETRICFIGUREDLL_EXPORTS
#define GEOMETRICFIGUREDLL_API __declspec(dllexport)
#else
#define GEOMETRICFIGUREDLL_API __declspec(dllimport)
#endif // GEOMETRICFIGUREDLL_EXPORTS


class GEOMETRICFIGUREDLL_API Figure {
private:
	int numSides{};
	std::string name{};

protected:
	Figure(int numSides, std::string name);

public:
	Figure();

	std::string getName() const;
	int getNumSides() const;
	virtual void printInfo() const = 0;
};


class GEOMETRICFIGUREDLL_API Triangle : public Figure {
private:
	int a{}, b{}, c{}, A{}, B{}, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C, std::string name = "Треугольник");

	void printInfo() const override;
};


class GEOMETRICFIGUREDLL_API EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a);
};


class GEOMETRICFIGUREDLL_API IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B);
};


class GEOMETRICFIGUREDLL_API RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B);
};


class GEOMETRICFIGUREDLL_API Quadrilateral : public Figure {
private:
	int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Четырёхугольник");

	void printInfo() const override;
};


class GEOMETRICFIGUREDLL_API Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B,
		std::string name = "Параллелограмм");
};


class GEOMETRICFIGUREDLL_API Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b, std::string name = "Прямоугольник");
};


class GEOMETRICFIGUREDLL_API Square : public Rectangle {
public:
	Square(int a);
};


class GEOMETRICFIGUREDLL_API Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B);
};