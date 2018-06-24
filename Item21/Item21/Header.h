#pragma once

class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator)
	{}
	void Print() const;

private:
	int n, d; // numerator and denominator
	friend const Rational& operator*(const Rational& lhs, const Rational& rhs); 
	friend bool operator==(const Rational& lhs, const Rational& rhs);
};
