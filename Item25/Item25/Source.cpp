#include "Widget.h"
using namespace WidgetStuff;


template<typename T>
void doSomething(T& obj1, T& obj2)
{
	using std::swap;	// make std::swap available in this function

	swap(obj1, obj2);	// call the best swap for objects of type T
}

int main()
{
	std::vector<double> vd1 = { 1.1, 2.2, 3.3 };
	Widget<double> w1(1, 2, 3, vd1), w2;

	Widget<double> w3(w1);
	std::vector<double> vd2 = { 4.4, 5.5, 6.6 };
	Widget<double> w4(4, 5, 6, vd2);

	w2 = w1 = w4;

	swap(w2, w3);

	doSomething(w2, w3);
}


