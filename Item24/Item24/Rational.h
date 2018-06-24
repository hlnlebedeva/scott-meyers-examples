#pragma once


class Rational
{
public:
	Rational(int numerator = 0, int denomerator = 1) : n(numerator), d(denomerator) // ctor is deliberately not explicit;
	{}												// allows implicit int-to Rational conversions

	int numerator() const;	// accessors for numerator and
	int deniminator() const; // deniminator

	void Print();

	//const Rational operator*(const Rational& rhs) const;
private:
	int n;
	int d;
};

const Rational operator*(const Rational& lhs, const Rational& rhs); // now a non-member function
