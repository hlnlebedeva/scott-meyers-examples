#pragma once

void logCall(const std::string& funcName);

class Date // for date in time
{
public:
	Date() : day(0), month(0), year(0) {};
	Date(int day, int month, int year) : day(day), month(month), year(year)
	{};
	void Print();

private:
	int day;
	int month;
	int year;
};


class Customer
{
public:
	Customer()
	{};
	Customer(const std::string name, Date date) : name(name), lastTransaction(date)
	{};
	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);
	virtual void Print();
	
private:
	std::string name;
	Date lastTransaction;
};


class PriorityCustomer : public Customer	// a derived class
{
public:
	PriorityCustomer() {};
	PriorityCustomer(std::string name, Date lastTr, int priority) : Customer(name, lastTr), priority(priority)
	{};
	PriorityCustomer(const PriorityCustomer& rhs);
	PriorityCustomer& operator=(const PriorityCustomer& rhs);
	void Print();
private:
	int priority;

};
