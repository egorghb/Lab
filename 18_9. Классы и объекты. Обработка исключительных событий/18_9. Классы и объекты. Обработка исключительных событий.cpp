#include <iostream>
#include "List.h"



int main()
{
	setlocale(LC_ALL, "Rus");
	try {
		List x(2);
		List y;
		List z(30);
		cout << x;
		cout << "Number? " << endl << ">";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		++z;
		cout << z;
	}
	catch (int a)
	{
		cout << "ERROR!!! " << a <<endl;
	}
	return 0;
}