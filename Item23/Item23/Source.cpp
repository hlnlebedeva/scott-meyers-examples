#include <stdlib.h>
#include <iostream>
#include "WebBrowser.h"
#include "WebBrowserBookmarks.h"
#include "WebBrowserCookies.h"



int main()
{
	WebBrowserStuff::WebBrowser w;

	//w.clearEverything();

	WebBrowserStuff::addBookmarksToBrowser(w, 2);
	WebBrowserStuff::addCookiesToBrowser(w, 3);
	WebBrowserStuff::clearBrowser(w);
	std::system("pause");
	

}