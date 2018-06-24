#pragma once

class Transaction // base class for all transactions
{
public:
	explicit Transaction(const std::string& logInfo);

	void logTransaction(const std::string& logInfo) const; // now a non-virtual func

};


class BuyTransaction : public Transaction   // derived class
{
public:
	BuyTransaction() : Transaction(crealeLogString())
	{}
private:
	static std::string crealeLogString() { return "BuyTransaction"; };
};


class SellTransaction : public Transaction  // derived class
{
public:
	SellTransaction() :Transaction(crealeLogString())
	{}
private:
	static std::string crealeLogString() { return "SellTransaction"; };
};
	