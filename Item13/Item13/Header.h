#pragma once


enum InvestmentType { Bond, Stock };


class Investment // root class of hierarchy of investment types
{
public:
	Investment();
	virtual ~Investment();

private:
	long inv[10000];
};


class StockInvestment : public Investment
{
public:
	StockInvestment();
	~StockInvestment();
private:
	long stockInv[10000];
};


class BondInvestment : public Investment
{
public:
	BondInvestment();
	~BondInvestment();
private:
	long bondInv[10000];
};