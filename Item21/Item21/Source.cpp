#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Header.h"



void Rational::Print() const
{
	std::cout << n << "/" << d << "\n";
}

/*
const Rational& operator*(const Rational & lhs, const Rational & rhs)
{
Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
return result;
}


const Rational& operator*(const Rational & lhs, const Rational & rhs) // warning! more bad code
{
	Rational *result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return *result;
}
*/

const Rational& operator*(const Rational & lhs, const Rational & rhs) // warning! yet more bad code !
{
	static Rational result;
	result.n = lhs.n * rhs.n;
	result.d = lhs.d * rhs.d;
	return result;
}


bool operator==(const Rational & lhs, const Rational & rhs)
{
	return lhs.n == rhs.n && lhs.d == rhs.d;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Rational a(1, 2);	// a = 1/2
	Rational b(3, 5);	// b = 3/5
	const Rational& c = a * b;	// c should be 3/10

	a.Print();
	b.Print();
	c.Print();



	//const Rational* pc = &c;
		
	//delete &c;

	Rational w, x, y, z;

	w = x * y * z;

	Rational d(1, 2), e(3,4), f(5,6), g(6,7);

	if ((d*e) == (f*g))
		std::cout << "Oops!\n";

	//delete &w;

	system("pause");
}