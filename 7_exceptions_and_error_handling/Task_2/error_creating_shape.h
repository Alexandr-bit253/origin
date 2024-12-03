#pragma once
#include <iostream>


class ErrorCreatingShape : public std::domain_error {
public:
	ErrorCreatingShape(const char* message);
};