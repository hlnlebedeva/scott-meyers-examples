#include "Rational.h"

const Rational Rational::operator*(const Rational & rhs)
{
	return Rational(m * rhs.Nominator(), n * rhs.Denominator());
}