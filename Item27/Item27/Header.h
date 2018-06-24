#pragma once

class Widget
{
public:
	explicit Widget(int size) : sz(size) 
	{}
	int Size() const { return sz; }
private:
	int sz;
};


class Base1
{
private:
	int a[100];
};

class Base2
{};

class Derived : public Base1, public Base2
{
private:
	int d[200];
};


class Window	// base class
{
public:
	Window() : size(0) {}

	explicit Window(int sz) : size(sz) 
	{}

	virtual void onResize(int newSize) // base onResize impl
	{
		size = newSize;
	}

	int Size() const { return size; }

	virtual void blink() {}		// default impl is no-op;
								// see Item 34 for why a default impl may be a bad idea

private:
	int size;
};


class SpecialWindow : public Window // derived class
{
public:
	SpecialWindow() : size2(0)
	{}

	explicit SpecialWindow(int sz1, int sz2) : Window(sz1), size2(sz2)
	{}

	int Size2() const { return size2; }

	virtual void onResize(int sz1, int sz2)	// derived onResize() impl;
	{
		Window::onResize(sz1);	// call Window::onResize on *this
		size2 = sz2;      // do SpecialWindow-specific stuff
	}

	void blink();		// in this class, blink does something


private:

	int size2;
};