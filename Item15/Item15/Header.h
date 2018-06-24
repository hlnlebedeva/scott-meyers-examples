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


int daysHeld(const Investment *pi);



class FontResource
{
public:
	FontResource() : size(10)
	{}
	void ChangeSize(int newSize) { size = newSize; }
	int GetSize() { return size; }
private:
	int size;
};

class FontHandle
{
public:
	FontHandle(FontResource& fontRes, int userCode) : fontRes(fontRes), userCode(userCode) {  }
	void ChangeSize(int newSize) { fontRes.ChangeSize(newSize); }
	int GetSize() { return fontRes.GetSize(); }
	bool operator==(FontHandle other)
	{
		return userCode == other.userCode;
	}
private:
	FontResource& fontRes;
	int userCode;
};

void releaseFont(FontHandle f);

class Font
{		// RAII class
public:
	explicit Font(FontHandle fh) : f(fh) //use pass-by-value, because the C API does
	{}

	~Font() { releaseFont(f); }

	operator FontHandle() const { return f; } // implicit conversion function

	//FontHandle get() const { return f; }	// explicit conversion function
private:
	FontHandle f; // the raw font resource
};

