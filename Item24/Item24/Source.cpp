#include <stdlib.h>
#include <iostream>
#include "Rational.h"

int main()
{
	Rational oneEighth(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEighth;	// fine 

	result.Print();

	result = result * oneEighth;	// fine

	result.Print();

	result = oneHalf * 2;		// fine (error with explicit ctor)
	//result = oneHalf.operator*(2); //fine   - for memeber-operator*

	result.Print();

	const Rational temp(2);   // create temporary Rational object from 2

	result = oneHalf * temp; // same as oneHalf.operator*(temp);

	result.Print();

	result = 2 * oneHalf;		// error (even with non-explicit ctor) for member-operator*
	//result = 2.operator*(oneHalf);	// error

	result.Print();

	std::system("pause");


}