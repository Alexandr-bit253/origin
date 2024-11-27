#include <cmath>

#include "operations.h"


int mAdd(const int& num1, const int& num2) {
	return num1 + num2;
}


int mSub(const int& num1, const int& num2) {
	return num1 - num2;
}


int mMult(const int& num1, const int& num2) {
	return num1 * num2;
}


float mDiv(const int& num1, const int& num2) {
	return static_cast<float>(num1) / num2;
}


int mPow(const int& num1, const int& num2) {
	return pow(num1, num2);
}