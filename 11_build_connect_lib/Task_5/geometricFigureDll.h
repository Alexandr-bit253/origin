#pragma once

#include<iostream>

//#ifdef GEOMETRICFIGURE_EXPORTS
//#define GEOMETRICFIGURE_API __declspec(dllexport)
//#else
//#define GEOMETRICFIGURE_API __declspec(dllimport)
//#endif // GEOMETRICFIGUREDLL_EXPORTS


class Figure {
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


class Triangle : public Figure {
private:
	int a{}, b{}, c{}, A{}, B{}, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C, std::string name = "Треугольник");

	void printInfo() const override;
};


class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a);
};


class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B);
};


class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B);
};


class Quadrilateral : public Figure {
private:
	int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, 
	std::string name = "Четырёхугольник");

	void printInfo() const override;
};


class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B,
		std::string name = "Параллелограмм");
};


class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b, std::string name = "Параллелограмм");
};


class Square : public Rectangle {
public:
	Square(int a);
};


class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B);
};