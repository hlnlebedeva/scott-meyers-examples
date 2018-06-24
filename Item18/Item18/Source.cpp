#include <stdlib.h>
#include <iostream>
#include <memory>
#include "Header.h"
#include "Investment.h"


void getRidOfInvestment(Investment* p)
{
	std::cout << "Deleter\n";
	delete p;
	system("pause");
}


std::tr1::shared_ptr<Investment> createInvestment(InvestmentType type = Bond) // return ptr 
{
	switch (type)
	{
	case Bond:
	{
		return std::shared_ptr<Investment>(new BondInvestment, getRidOfInvestment);
	}
	case Stock:
	{
		return std::shared_ptr<Investment>(new StockInvestment, getRidOfInvestment);
	}
	}
	return NULL;
}






int main()
{
	//Date d(30, 3, 1995);
	//Date d1(Day(30), Month(3), Year(1995));
	//Date d2(Month(3), Day(30), Year(1995));
	Date d(Month::Mar(), Day(30), Year(1995));

	std::shared_ptr<Investment> pInv = createInvestment();

	std::tr1::shared_ptr<Investment> pInv1(0, getRidOfInvestment);

	//std::tr1::shared_ptr<Investment> pInv1(static_cast<Investment*>(0), getRidOfInvestment);
}