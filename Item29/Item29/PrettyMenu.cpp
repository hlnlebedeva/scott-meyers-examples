#include <istream>
#include "Mutex.h"
#include "PrettyMenu.h"


void lock(Mutex *pm)	// lock mutex pointed to by pm
{
	pm->Acquire();
}

void unlock(Mutex *pm)		// unlock the mutex
{
	pm->Free();
}


void PrettyMenu::changeBackground(std::istream & imgSrc)
{
	lock(&mutex);	// acquire mutex (as in Item 14)

	delete bgImage;	// get rid of old background
	++imageChanges;	// update image change count
	bgImage = new Image(imgSrc);	// install new background

	unlock(&mutex);		// release mutex
}

Image::Image(std::istream & imgSrc)
{
		// get length of file:
		imgSrc.seekg(0, imgSrc.end);
		std::streamoff length = imgSrc.tellg();
		imgSrc.seekg(0, imgSrc.beg);

		std::string str;
		str.resize(length, ' '); // reserve space
		char* begin = &*str.begin();

		imgSrc.read(begin, length);

		buf = str;
}
