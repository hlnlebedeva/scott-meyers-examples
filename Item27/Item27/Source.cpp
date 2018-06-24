#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>
#include "Header.h"

using namespace std;

typedef std::vector<std::shared_ptr<Window>> VPM;  
typedef std::vector<std::shared_ptr<SpecialWindow>> VPSW;


void doSomeWork(const Widget& w)
{
	cout << w.Size() << "\n";
}


void SpecialWindow::blink()
{
	cout << "SpecialWindow::blink\n";
}



int main()
{
	const char* name = "Helen";

	char* name1 = const_cast<char*>(name);

	char* name2 = (char*)name;

	doSomeWork(Widget(15));	// create Widget from int
							// with function-style cast
	doSomeWork(static_cast<Widget>(15));  // create Widget from int
											// with C++-style cast

	int x = 4, y = 8;

	double d = static_cast<double>(x) / y;	// divide x by y, but use
											// floating point division

	std::cout << d << "\n";


	Derived dc;

	Derived *pd = &dc;

	Base1 *pb1 = &dc;	// implicitly convert Derived* => Base1*
	Base2 *pb2 = &dc;


	std::cout << pd << "\n";
	std::cout << pb1 << "\n";
	std::cout << pb2 << "\n";

	Window w(4);

	w.onResize(5);

	cout << "w.Size = " << w.Size() << "\n";

	SpecialWindow sw;

	cout << "sw.Size = " << sw.Size() << ", sw.Size2 = " << sw.Size2() << "\n";

	sw.onResize(1, 2);

	cout << "sw.Size = " << sw.Size() << ", sw.Size2 = " << sw.Size2() << "\n";


	SpecialWindow sw1(10, 12);

	cout << "sw1.Size = " << sw1.Size() << ", sw1.Size2 = " << sw1.Size2() << "\n";

	VPM winPtr = {shared_ptr<Window>(new Window()), shared_ptr<Window>(new SpecialWindow())};

	for (VPM::iterator iter = winPtr.begin(); 
		iter != winPtr.end();				
		++iter)
	{
		//if (SpecialWindow *psw = dynamic_cast<SpecialWindow*>(iter->get()))		//undesirable code uses dynamic_cast
		//	psw->blink();
		(*iter)->blink();
	}

    VPSW winPtrs = {shared_ptr<SpecialWindow>(new SpecialWindow)};

	for (VPSW::iterator iter = winPtrs.begin();	// better code: uses no dynamic_cast
	iter != winPtrs.end();
		++iter)
	{
		(*iter)->blink();
	}
	
	system("pause");
	

}