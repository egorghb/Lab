#include <iostream>
#include "List.h"
#include "Error.h"
using namespace std;

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
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}