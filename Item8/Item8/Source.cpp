
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
		#define new DBG_NEW
	#endif
#endif


#include <stdlib.h>
#include <crtdbg.h>
//#include <vld.h>
#include <vector>
#include <iostream>
#include"Header.h"


void doSomething2()
{
	Widget a;

}
void doSomething()
{
	
		std::vector<Widget> v(1);
		doSomething2();
	
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	try
	{
		DBConn dbc(DBConnection::create(""));

		dbc.close();
		
		//doSomething();
	}
	catch (DBConnectException)
	{
		std::cout << "Catch DBConnectException\n";
	}
	catch (...)
	{
		std::cout << "Catch\n";
	}

	std::cout << "End!!!\n";
	system("pause");
}
