#include <iostream>
#include "WebBrowser.h"

using namespace std;
using namespace WebBrowserStuff;

/*
void WebBrowser::clearEverything()
{
clearCache();
clearHistory();
removeCookies();
}
*/


void WebBrowser::clearCache()
{
	cout << "clear cache\n";
}

void WebBrowser::clearHistory()
{
	cout << "clear history\n";
}

void WebBrowser::removeCookies()
{
	cout << "remove cookies\n";
}

void WebBrowserStuff::WebBrowser::addBookmark()
{
	cout << "bookmark added\n";
}

void WebBrowserStuff::WebBrowser::addCookie()
{
	cout << "cookie added\n";
}


void WebBrowserStuff::clearBrowser(WebBrowser& wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}