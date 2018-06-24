#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <memory>
#include "Header.h"


Investment::Investment()
{
	std::cout << "Investment constructor\n";
}

Investment::~Investment()
{
	std::cout << "Investment destructor\n";
}

StockInvestment::StockInvestment()
{
	std::cout << "StockInvestment constructor\n";
}

StockInvestment::~StockInvestment()
{
	std::cout << "StockInvestment destructor\n";
}

BondInvestment::BondInvestment()
{
	std::cout << "BondInvestment constructor\n";
}

BondInvestment::~BondInvestment()
{
	std::cout << "BondInvestment destructor\n";
}

Investment* createInvestment(InvestmentType type) // return ptr 
{
	
	switch (type)
	{
	case Bond :
		return new BondInvestment();
	case Stock :
		return new StockInvestment();
	}
	return NULL;
}

void f(InvestmentType type)
{
	std::auto_ptr<Investment> pInv1(createInvestment(type)); // call factory function
	
	// automatically delete pInv via auto_ptr's dtor
}

void f1(InvestmentType type)
{ 
	std::cout << "f1\n";
	std::tr1::shared_ptr<Investment> pInv(createInvestment(type));   // call factory function
} // automatically delete via shared_ptr's dtor


void f2()
{
	std::cout << "f2\n";

	std::auto_ptr<Investment> pInv1(createInvestment(Bond)); // pInv1 points to the object returned from createInvestment

	std::auto_ptr<Investment> pInv2(pInv1); // pInv2 now points to the object; pInv1 is now null

	pInv1 = pInv2;			// now pInv1 points to the object, and pInv2 is null
}


void f3()
{
	std::cout << "f3\n";

	std::tr1::shared_ptr<Investment> pInv1(createInvestment(Stock)); // call factory function, points to object returnd from createInvestment

	std::tr1::shared_ptr<Investment> pInv2(pInv1); // both pInv1 and pInv2 now point to the object

	pInv1 = pInv2; // ditto - nothing has changed

} // automatically delete

/*
void f4()
{
std::cout << "f4\n";

std::unique_ptr<Investment> pInv1(createInvestment(Bond));
std::unique_ptr<Investment> pInv2(pInv1);

pInv1 = pInv2;
}
*/




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//f(Bond);
	//f(Stock);

	
	f1(Stock);

	f2();

	f3();

	std::auto_ptr<std::string> asp(new std::string[10]); // bad idea! the wrong delete will be used

	std::tr1::shared_ptr<int> spi(new int[1024]); // same problem

	std::system("pause");
}