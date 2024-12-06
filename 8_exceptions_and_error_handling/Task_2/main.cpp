#include <iostream>

#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrilateral.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "error_creating_shape.h"

using namespace std;


static void printInfo(Figure* figure) {
	figure->printInfo();
}


int main() {
	setlocale(LC_ALL, "rus");
	try
	{
		Triangle triagle{ 10, 20, 30, 50, 60, 70 };
		printInfo(&triagle);
		RightTriangle rightTriangle{ 10, 20, 30, 30, 60, 90};
		printInfo(&rightTriangle);
		IsoscelesTriangle isoscelesTriangle{ 20, 40, 20, 70, 40, 70 };
		printInfo(&isoscelesTriangle);
		EquilateralTriangle equilateralTriangle{ 30, 30, 30, 60, 60, 60 };
		printInfo(&equilateralTriangle);

		Quadrilateral quadrilateral{ 10, 20, 30, 40, 60, 120, 80, 100 };
		printInfo(&quadrilateral);
		Rectangle rectangle{ 30, 40, 30, 40, 90, 90, 90, 90 };
		printInfo(&rectangle);
		Square square{ 40, 40, 40, 40, 90, 90, 90, 90 };
		printInfo(&square);
		Parallelogram parallelogram{ 30, 40, 30, 40, 70, 110, 70, 110 };
		printInfo(&parallelogram);
		Rhombus rhombus{ 40, 40, 40, 40, 40, 140, 40, 140 };
		printInfo(&rhombus);
	}
	catch (const ErrorCreatingShape& err)
	{
		std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
	}
}