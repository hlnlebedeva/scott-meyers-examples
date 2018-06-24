#pragma once

enum InvestmentType { Bond, Stock };


class Investment // root class of hierarchy of investment types
{
public:
	Investment() : daysHeld(0), taxFree(false)
	{}
	virtual ~Investment() {};
	int GetDaysHeld() const { return daysHeld; }
	bool IsTaxFree() const { return taxFree; }
private:
	long inv[10000];
	int daysHeld;
	bool taxFree;
};


class StockInvestment : public Investment
{
private:
	long stockInv[10000];
};


class BondInvestment : public Investment
{
private:
	long bondInv[10000];
};

