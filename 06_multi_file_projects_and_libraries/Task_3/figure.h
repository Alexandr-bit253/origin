#pragma once
#include <iostream>


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