#pragma once
//#include "WebBrowser.h"

namespace WebBrowserStuff
{
	// bookmark-related convenience functions

	
	void addBookmarksToBrowser(WebBrowser& wb, int n)
	{
		for (int i = 0; i < n; i++)
			wb.addBookmark();
	}
}