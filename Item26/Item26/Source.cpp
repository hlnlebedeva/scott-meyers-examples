#include <stdlib.h>
#include <string>
#include <iostream>
#include "Header.h"

const int MinimumPasswordLength = 8;

void encrypt(std::string& s)	// encrypts s in place
{
	using namespace std;

	for (int i = s.length() - 1; i >= s.length() / 2; i--)
	{
		swap(s[i], s[s.length() - 1 - i]);
	}

}


// finally, the best way to define and initialize encrypted

std::string encryptPassword(const std::string& password)
{
	using namespace std;

	if (password.length() < MinimumPasswordLength)
		throw logic_error("Password is too short;");
	
	string encrypted(password); // define and initialize via copy constructor

	encrypt(encrypted);

	return encrypted;
}


int main()
{
	using namespace std;
	try
	{
		cout << encryptPassword("47lediga") << "\n";
	}
	catch (logic_error e)
	{
		cout << e.what() << "\n";
	}

	// Approach A: define outside loop

	Widget w;
	int n = 5;

	for (int i = 0; i < n; ++i)
	{
		w = i;
		w.Print();
	}

	// Approach B: define inside loop

	for (int i = 0; i < n; ++i)
	{
		Widget w(i);
		w.Print();
	}



	system("pause");
}