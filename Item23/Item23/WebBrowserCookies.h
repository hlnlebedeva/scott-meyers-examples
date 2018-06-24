#pragma once
//#include "WebBrowser.h"

namespace WebBrowserStuff
{
	// cookie-related convenience functions

	void addCookiesToBrowser(WebBrowser& wb, int n)
	{
		for (int i = 0; i < n; i++)
			wb.addCookie();
	}
}
