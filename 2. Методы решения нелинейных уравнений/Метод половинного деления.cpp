#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return acos(x) - sqrt(1 - 0.3 * x * x * x);
}

int main() {
	double a, b, c, e;
	a = 0;
	b = 1;
	e = pow(10, -6);
	while (abs(a - b) >= e) {
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	cout << b << endl;
	return 0;
}