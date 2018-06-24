#include <iostream>
#include "Header.h"

Widget::Widget(const Widget& other)
{
	pb = new Bitmap(*other.pb);
}

Widget& Widget::operator=(const Widget& rhs)
{
	Widget temp(rhs);
	swap(temp);
	return *this;
}

void Widget::Print()
{
	pb->Print();
}

void Bitmap::Print()
{
	std::printf(" a = %d\n", a);
}

void Widget::swap(Widget& rhs)
{
	//std::swap(*(this->pb), *(rhs.pb));  // also correct
	std::swap(pb, rhs.pb); // more efficient
	//Bitmap* temp = this->pb;
	//this->pb = rhs.pb;
	//rhs.pb = temp;
}

int main()
{
	Widget w;
	Widget *px = &w, *py = &w;
	Widget a[1];
	Widget w1(1);
	int i = 0, j = 0;


	w.Print();


	w = w;

	//a[0] = w; 
	//a[i] = a[j];  // its OK !

	//*px = *py;

	w.Print();

	w = w1;

	w.Print();

	std::system("pause");


}