#include <stdlib.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <exception>
#include <boost/thread.hpp>

#include "Mutex.h"
#include "PrettyMenu.h"



int main()
{

	std::ifstream filestr("text.txt", std::ifstream::binary);
	std::ifstream filestr2("text2.txt", std::ifstream::binary);


	if (filestr) 
	{
		PrettyMenu pm = PrettyMenu(new Image(filestr));
		filestr.close();

		//std::cout << str << "\n";

		if (filestr2)
		{
			pm.changeBackground(filestr2);
			filestr2.close();
		}
		else
			std::cout << "Could not open text2.txt\n";

	}
	else 
		std::cout << "Could not open text.txt\n";
}
