#include <iostream> 
#include "Rational.h"

int Rational::numerator() const
{
	return n;
}

int Rational::deniminator() const
{
	return d;
}

void Rational::Print()
{
	std::cout << n << "/" << d << "\n";
}

/*
const Rational Rational::operator*(const Rational & rhs) const
{
	return Rational(n * rhs.numerator(), d * rhs.deniminator());
}
*/

const Rational operator*(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(),
						lhs.deniminator() * rhs.deniminator());
}
