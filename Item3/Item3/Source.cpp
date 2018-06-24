#include "Header.h"
#include "Rational.h"
using namespace std;


void f1(const Widget *pw)
{}

void f2(Widget const *pw)
{}

void print(const TextBlock& ctb)	// in this function, ctb is const
{
	std::cout << ctb[0];			// calls const TextBlock::operator
}

int main()
{
	char in;

	char greeting[] = "Hello";
	char shortGreeting[] = "Hy!";


	char *p = greeting; // non-const pointer, non-const data


	//const char *p = greeting; // non-const pointer, const data

	//char * const p = greeting; // const pointer, non-const data

	//const char * const p = greeting; // const pointer, const data;

	cout << p << "\n";

	p = shortGreeting;
	cout << p << "\n";

	p[2] = '?';
	cout << p << "\n";




	vector<int> vec = { 1, 2 };

	vec.push_back(3);
	vec.push_back(4);

	for (size_t i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << '\n';

	const vector<int>::iterator iter = vec.begin(); // iter acts like a T* const
	*iter = 10;
	//++iter;

	for (size_t i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << '\n';

	vector<int>::const_iterator citer = vec.begin(); //citer acts like a const T*

	//*citer = 10; // error! *citer is const
	++citer; // fine, changes citer

	for (; citer != vec.end(); ++citer)
	   cout << *citer << ' ';

	cout << '\n';

	TextBlock tb("Hello");
	cout << tb[0] << " - calls non-const TextBlock::operator" << '\n';

	const TextBlock ctb("Word");

	cout << ctb[0] << " - calls const TextBlock::operator" << '\n';

	print(ctb);
	print(tb); 

	std::cout << tb[0];		// fine - reading a non-const TextBlock

	tb[0] = 'x';			// fine - writing a non-const TextBlock

	std::cout << ctb[0];	// fine - reading a const TextBlock

	//ctb[0] = 'x';			// error! - writing a const TextBlock

	cout << '\n';

	const CTextBlock cctb("Hello!"); //declare constant object

	char *pc = &cctb[0];		// call the const operator[] to get a pointer to cctb's data

	*pc = 'J';
	
	cout << &cctb[0];

	cout << cctb.length();

	cin >> in;

	Rational r1(2, 3), r2(2, 3);
	
	Rational r3 = r1 * r2;

	//r1 * r2 = r3;
}
