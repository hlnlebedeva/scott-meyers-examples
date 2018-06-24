#include <string>
#include <iostream>
#include "Header.h"

Transaction::Transaction(const std::string& logInfo)
{
	logTransaction(logInfo); // now a non-virtual call
}

void Transaction::logTransaction(const std::string& logInfo) const
{
	std::cout << logInfo << "\n";
}


int main()
{
	BuyTransaction btr;
	SellTransaction str;

	std::cout << typeid(btr).name() << "\n";
	system("pause");
}