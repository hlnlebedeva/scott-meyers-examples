#pragma once

class Bitmap
{
public:
	Bitmap() : a(0) 
	{};
	Bitmap(int i)
	{
		a = i;
	};
	void Print();
private:
	int a;
};

class Widget
{
public:
	Widget() { pb = new Bitmap(); };
	Widget(int i) { pb = new Bitmap(i); };
	Widget(const Widget& other);
	~Widget() { delete pb; };
	Widget& operator=(const Widget& rhs);
	void Print();
private: 
	void swap(Widget& rhs);

	Bitmap *pb;
};

