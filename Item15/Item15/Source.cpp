#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <memory>
#include <list>
#include "Header.h"




Investment* createInvestment(InvestmentType type = Bond) // return ptr 
{

	switch (type)
	{
	case Bond:
		return new BondInvestment();
	case Stock:
		return new StockInvestment();
	}
	return NULL;
}

int daysHeld(const Investment * pi)
{
	return pi->GetDaysHeld();
}

std::list<FontHandle> handles;

FontHandle getFont(FontResource& fr)
{
	FontHandle fh(fr, 1);
	handles.push_back(fh);
	return fh;
}

void releaseFont(FontHandle f)
{
	handles.remove(f);
}

void chageFontSize(FontHandle f, int newSize)
{
	f.ChangeSize(newSize);
}


void f(FontResource& fr)
{
	Font f(getFont(fr));
	int newFontSize = 5;

	//std::cout << "size = " << f.get().GetSize() << "\n";

	std::cout << "size = " << FontHandle(f).GetSize() << "\n";

	//chageFontSize(f.get(), newFontSize); // explicitly convert 
										 // Font to FontHandle
	chageFontSize(f, newFontSize);		// implicitly convert Font
										// to FontHandle

	//std::cout << "size = " << f.get().GetSize() << "\n";
	std::cout << "size = " << FontHandle(f).GetSize() << "\n";

}

FontResource FontRes;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::shared_ptr<Investment> pInv(createInvestment());

	int days = daysHeld(pInv.get());

	std::cout << "days = " << days << "\n";

	std::tr1::shared_ptr<Investment>    // have tr1::shared_ptr 
		pi1(createInvestment());		// manage a resource

	bool taxable1 = !(pi1->IsTaxFree());	// acces resource via operator->

	std::cout << "taxable1 = " << taxable1 << "\n";

	std::auto_ptr<Investment> pi2(createInvestment()); // have auto_ptr
														// manage a resource

	bool taxable2 = !((*pi2).IsTaxFree());	// access resource via operator*

	std::cout << "taxable2 = " << taxable2 << "\n";


	f(FontRes);

	Font f1(getFont(FontRes));

	FontHandle f2 = f1;		// oops! meant to copy a Font object, but instead implicitly
							// converted f1 into its underlying
							// FontHandle, then copied that



	system("pause");
}


