#include "error_creating_shape.h"


ErrorCreatingShape::ErrorCreatingShape(const char* message) : 
	std::domain_error(message) {}