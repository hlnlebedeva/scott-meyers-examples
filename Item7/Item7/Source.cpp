
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
		#define new DBG_NEW
	#endif
#endif
	
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
//#include <vld.h> 
#include "Header.h"
using namespace std;



void TimeKeeper::getTime()
{
	cout << "TimeKeeper time \n";
	return;
}

void AtomicClock::getTime()
{
	cout << "AtomicClock time \n";
	return;
}

void WaterClock::getTime()
{
	cout << "WaterClock time \n";
}

void WristClock::getTime()
{
	cout << "WristClock time \n";
}

enum ClockType { Atomic, Water,	Wrist};


TimeKeeper* getTimeKeeper(ClockType type)
{
	switch (type)
	{
	case Atomic:
		return new AtomicClock();
	case Water:
		return new  WaterClock();
	case Wrist:
		return new WristClock();
	default:
		return NULL;
	}
}

void getTime(ClockType type)
{
	TimeKeeper *ptk;

	ptk = getTimeKeeper(type);
	ptk->getTime();

	delete ptk;

}

void f()
{
	AWOVInh inh;

	inh.Method();
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	char c;
		
	getTime(Atomic);
	getTime(Water);
	getTime(Wrist);

	
	SpecialString *pss = new SpecialString("Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom Impending Doom");
	std::string *ps;

	ps = pss; 

	cout << ps->c_str() << "\n";

	delete ps;
	
	f();
	

	//_CrtDumpMemoryLeaks();
	system("pause");
}