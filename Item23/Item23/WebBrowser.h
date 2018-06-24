#pragma once
namespace WebBrowserStuff
{
	class WebBrowser
	{
	public:
		//void clearEverything(); // calls clearCache, clearHistory and removeCookies - bad approache
		void clearCache();
		void clearHistory();
		void removeCookies();
		void addBookmark();
		void addCookie();
	};

	// "core" related functionality, e.g.
	// non-member functions almost
	// all clients need

	void clearBrowser(WebBrowser& wb);

}

