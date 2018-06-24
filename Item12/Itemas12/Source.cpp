#include <stdlib.h>
#include <string>
#include <iostream>
#include "Header.h"

void logCall(const std::string & funcName)
{
	std::cout << funcName << "\n";
}

void Date::Print()
{
	printf("%02d/%02d/%04d\n", day, month, year);
	//std::cout << day << "/" << month << "/" << year << "/n";
}

Customer::Customer(const Customer & rhs) : name(rhs.name), lastTransaction(rhs.lastTransaction)
{
	logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer & rhs)
{
	logCall("Customer copy assignment operator");

	name = rhs.name; // copy rhs's data
	lastTransaction = rhs.lastTransaction;

	return *this;
}

void Customer::Print()
{
	std::cout << "name = " << name << "\n";
	std::cout << "lastTransaction = ";
	lastTransaction.Print();
}

PriorityCustomer::PriorityCustomer(const PriorityCustomer & rhs) : Customer(rhs), // invoke base class copy ctor
	priority(rhs.priority)
{
	logCall("PriorityCustomer copy constructor");
}

PriorityCustomer & PriorityCustomer::operator=(const PriorityCustomer & rhs)
{
	logCall("PriorityCustomer copy assignment operator");

	Customer::operator=(rhs); // assing base class parts
	priority = rhs.priority;

	return *this;
}

void PriorityCustomer::Print()
{
	Customer::Print();
	std::cout << priority << "\n";
}

int main()
{
	Customer c1("James", Date(1, 1, 2006));
	Customer c2 = c1;
	Customer c3;

	c1.Print();
	c2.Print();

	c3 = c1;

	c3.Print();

	PriorityCustomer pc1("Mary", Date(2, 2, 2010), 1);
	PriorityCustomer pc2 = pc1, pc3;

	pc1.Print();
	pc2.Print();

	pc3 = pc1;

	pc3.Print();

	std::system("pause");
}
