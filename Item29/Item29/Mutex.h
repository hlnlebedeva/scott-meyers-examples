#pragma once

#include <windows.h>

class Mutex
{
public:
	Mutex() 
	{
		// Initialize the critical section one time only.
		if (!InitializeCriticalSectionAndSpinCount(&ñriticalSection,	// TO DO: replace to InitializeCriticalSection
			0x00000400))
			throw std::exception();  // TO DO: add text or use RuntimeError
	}

	~Mutex()
	{
		// Release resources used by the critical section object.
		DeleteCriticalSection(&ñriticalSection);
	}

	void Acquire() 
	{
		// Request ownership of the critical section.
		EnterCriticalSection(&ñriticalSection);
	}
	
	void Free() // TO DO: rename to Release
	{   
		// Release ownership of the critical section.
		LeaveCriticalSection(&ñriticalSection);
	}

private:
	
	CRITICAL_SECTION ñriticalSection;
};


