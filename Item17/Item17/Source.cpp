#include <stdlib.h>
#include <memory>
#include "Header.h"

int priority()
{
	return 1;
}

void processWidget(std::tr1::shared_ptr<Widget> pw, int priority)
{}

int main()
{
	processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority()); // a leak in  the call processWidget
		// can arise because an exception can untervene between new Widget and tr1::shared_ptr ctor
		// if priority executed between them 

	std::tr1::shared_ptr<Widget> pw(new Widget); // store newed object in a smart pointer in a
												// standalone statement

	processWidget(pw, priority());			// this call won't leak
												
}