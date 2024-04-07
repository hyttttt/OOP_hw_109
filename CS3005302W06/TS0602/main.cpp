// Name: ½²´ð¼ü
// Date:  April 6, 2021
// Last Update: April 6, 2021
// Problem statement: This C++ program designs a class to store prime numbers

#include "PrimeNumber.h"
#include <iostream>

using namespace std;

int main()
{	
	PrimeNumber p1, p2(13);	
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	cout << a.get() << endl;
	cout << p1.get() << endl;
	cout << b.get() << endl;
	cout << p2.get() << endl;

	return 0;
}
