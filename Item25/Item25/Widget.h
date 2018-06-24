#pragma once
#include <stdlib.h>
#include <vector>

namespace WidgetStuff
{


	template <typename T>
	class WidgetImpl
	{					// class for Widget data
	public:
		// details are unimportant
		WidgetImpl() : a(0), b(0), c(0)
		{}
		WidgetImpl(int a, int b, int c, const std::vector<double>& v) : a(a), b(b), c(c), v(v)
		{}
	private:
		int a, b, c;				// possibly lots of data -
		std::vector<T> v;		// expensive to copy!

	};


	template<typename T>
	class Widget
	{			// class using the pimpl idiom
	public:
		Widget()
		{
			pImpl = new WidgetImpl<T>();
		}

		Widget(int a, int b, int c, const std::vector<double>& v)
		{
			pImpl = new WidgetImpl<T>(a, b, c, v);
		}

		Widget(const Widget& rhs)
		{
			pImpl = new WidgetImpl<T>(*(rhs.pImpl));
		}

		Widget& operator=(const Widget& rhs) // to copy a Widget, copy its
		{									// WidgetImpl object. For
											//details on implementing 
			*pImpl = *(rhs.pImpl);			// operator= in general,
											// see Items 10, 11 and 12
			return *this;
		}

		~Widget()
		{
			delete pImpl;
		}

		void swap(Widget& other)
		{
			using std::swap;			// make std::swap available in this function
			swap(pImpl, other.pImpl);	// to swap Widgets, call their
		}								// pImpl pointers

	private:
		WidgetImpl<T> *pImpl;		// ptr to object with this
								// Widget's data
	};



	template<typename T>	    // non-member swap function;
	void swap(Widget<T>& a,	    // not part of the std namespace
		Widget<T>& b)					
	{
		a.swap(b);					// to swap Widgets, call their
	}								// swap member function


}