#include <iostream>
#include "Header.h"

void Widget::PrintA()
{
	std::cout << a << "\n";
}

int main()
{
	Widget w1, w2;

	w1.PrintA();
	w2.PrintA();

	w1 = 5;
	w2 = w1;

	w1.PrintA();
	w2.PrintA();

	w2 += w1;

	w1.PrintA();
	w2.PrintA();

	std::system("pause");

}