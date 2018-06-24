#include <stdlib.h>
#include <iostream>
#include <memory>
#include "Header.h"


void lock(Mutex *pm)
{
	if (pm->Locked)
	{
		std::cout << "already locked\n";
		return;
	}
	pm->Locked = true;
	std::cout << "locked\n";
}

void unlock(Mutex *pm)
{
	if (!pm->Locked)
	{
		std::cout << "already unlocked\n";
		return;
	}
	pm->Locked = false;
	std::cout << "unlocked\n";
}

int main()
{
	Mutex m; // defime the mutex you need to use

	{	// create block to define critical section

		Lock ml1(&m); // lock m

		Lock ml2(ml1);

		// perform critical section operations
	}	// automaticall unlock mutex at end of block

	std::system("pause");

}