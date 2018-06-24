#pragma once

class Widget
{
public:
	Widget() : i(0) {}
	Widget(int i) : i(i) {}
	void Print()
	{
		std::cout << "w=" << i << "\n";
	}
private:
	int i;
};

