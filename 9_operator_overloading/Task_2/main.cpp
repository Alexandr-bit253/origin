#include <iostream>
#include <numeric>

using namespace std;


class Fraction
{
private:
	int numerator_;
	int denominator_;

	void reduce() {
		int gcd = std::gcd(numerator_, denominator_);
		numerator_ /= gcd;
		denominator_ /= gcd;

		if (denominator_ < 0) {
			numerator_ = -numerator_;
			denominator_ = -denominator_;
		}
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;

		reduce();
	}

	bool operator==(const Fraction& other) {
		return numerator_ * other.denominator_ == other.numerator_ * denominator_;
	}

	bool operator!=(const Fraction& other) {
		return !(*this == other);
	}

	bool operator<(const Fraction& other) {
		return numerator_ * other.denominator_ < other.numerator_ * denominator_;
	}

	bool operator<=(const Fraction& other) {
		return *this < other || *this == other;
	}

	bool operator>(const Fraction& other) {
		return numerator_ * other.denominator_ > other.numerator_ * denominator_;
	}

	bool operator>=(const Fraction& other) {
		return *this > other || *this == other;
	}

	friend ostream& operator<<(ostream& os, const Fraction& f) {
		return os << f.numerator_ << "/" << f.denominator_;
	}

	Fraction operator+(const Fraction& other) {
		int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
		int newDenominator = denominator_ * other.denominator_;
		return Fraction(newNumerator, newDenominator);
	}

	Fraction operator-(const Fraction& other) {
		int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
		int newDenominator = denominator_ * other.denominator_;
		return Fraction(newNumerator, newDenominator);
	}
	
	Fraction operator*(const Fraction& other) const {
		int newNumerator = numerator_ * other.numerator_;
		int newDenominator = denominator_ * other.denominator_;
		Fraction result{ newNumerator, newDenominator };
		result.reduce();
		return result;
	}
	
	Fraction operator/(const Fraction& other) const {
		int newNumerator = numerator_ * other.denominator_;
		int newDenominator = denominator_ * other.numerator_;
		Fraction result{ newNumerator, newDenominator };
		result.reduce();
		return result;
	}

	Fraction& operator++() {
		numerator_ += denominator_;
		reduce();
		return *this;
	}

	Fraction operator++(int) {
		Fraction temp{ *this };
		numerator_ += denominator_;
		reduce();
		return temp;
	}

	Fraction& operator--() {
		numerator_ -= denominator_;
		reduce();
		return *this;
	}

	Fraction operator--(int) {
		Fraction temp{ *this };
		numerator_ -= denominator_;
		reduce();
		return temp;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	int nmr1{}, dnm1{}, nmr2{}, dnm2{};

	cout << "¬ведите числитель дроби 1: ";
	cin >> nmr1;
	cout << "¬ведите знаменатель дроби 1: ";
	cin >> dnm1;

	cout << "¬ведите числитель дроби 2: ";
	cin >> nmr2;
	cout << "¬вдите знаменатель дроби 2: ";
	cin >> dnm2;

	Fraction f1(nmr1, dnm1);
	Fraction f2(nmr2, dnm2);

	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << endl;
	cout << "«начение дроби 1 = " << f1 << endl;
	cout << f1 << "--" << " * " << f2 << " = " << (f1-- * f2) << endl;
	cout << "«начение дроби 1 = " << f1 << endl;

	return 0;
}