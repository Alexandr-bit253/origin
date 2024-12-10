#include "parallelogram.h"


Parallelogram::Parallelogram(int a, int b, int A, int B, 
	std::string name)
	: Quadrilateral(a, b, a, b, A, B, A, B, name) {
}