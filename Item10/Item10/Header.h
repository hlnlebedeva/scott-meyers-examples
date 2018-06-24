#pragma once

class Widget
{
public:
	Widget() : a(0)
	{}

	Widget& operator=(const Widget& rhs) // return type is a reference to the current class
	{
		a = rhs.a;
		return *this;		// return the left-hand object;
	}

	Widget& operator+=(const Widget& rhs) // the conventions applies to +=, -=, *=, etc.
	{
		a += rhs.a;
		return *this;
	}

	Widget& operator=(int rhs) //it applies even if the operator's parameter type is unconventional
	{
		a = rhs;
		return *this;
	}

	void PrintA();
	

private:
	int a;
};
