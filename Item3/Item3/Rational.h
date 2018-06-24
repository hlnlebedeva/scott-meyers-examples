#pragma once

class Rational
{
public:
	Rational() : m(0), n(0) {}
	Rational(int m, int n) : m(m), n(n) {}
	const Rational operator*(const Rational& rhs);
	int Nominator() const { return m; }
	int Denominator() const { return n; }
private:
	int m;
	int n;
};

