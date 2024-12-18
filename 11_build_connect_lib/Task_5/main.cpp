#include <iostream>

#include "geometricFigureDll.h"


using namespace std;


static void printInfo(Figure* figure) {
	figure->printInfo();
	cout << endl;
}


int main() {

	Triangle triagle{ 10, 20, 30, 50, 60, 70 };
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