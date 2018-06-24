#include <stdlib.h>
#include <string>
#include <iostream>
#include "Header.h"

bool validateStudent(const Student& s) // function taking a Student by value
{
	return true;
}

void Window::display() const
{
	std::cout << "display Window\n";
}

void WindowWithScrollBars::display() const
{
	std::cout << "display WindowWithScrollBars\n";
}

void printNameAndDisplay(Window& w)	
{
	std::cout << w.name() << "\n";
	w.display();
}

int main()
{
	Student plato("Plato", "Greece", "Socrates's school", "Greece"); // Plato studied under Socrates
	bool platoIsOK = validateStudent(plato); // call the function

	WindowWithScrollBars wwsb("WindowWithScrollBars");

	printNameAndDisplay(wwsb);

	system("pause");

}