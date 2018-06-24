#include <stdlib.h>
#include <string>

typedef std::string AddressLines[4];	// a person's address has 4 lines, each of wich is a string

int main()
{
	std::string *stringArray = new std::string[100];

	delete [] stringArray;

	std::string *stringPtr1 = new std::string;
	std::string *stringPtr2 = new std::string[100];

	delete stringPtr1; // delete an object
	delete[] stringPtr2;	//delete an array of objects

	std::string *pal = new AddressLines;	// note that "new AddressLines"
											// returns a string*, just like "new string[4]" would
	//delete pal;		// undefined!
	delete[] pal;	// fine
}