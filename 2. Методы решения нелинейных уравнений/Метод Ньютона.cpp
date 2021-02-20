#include <iostream>
#include <math.h>
using namespace std;

int main()
{
double x0, x1, y, y1, e, a, b;
a = 0;
b = 1;
e = 0.000001;
x0 = a;
x1 = x0 - ((acos(x0) - sqrt(1 - 0.3 * x0 * x0 * x0)) / (((9 * x0 * x0) / sqrt(20 * (1 - 0.3 * x0 * x0 * x0))) - (1 / sqrt(1 - x0 * x0))));
while (abs(x1 - x0) > e)
{
x0 = x1;
x1 = x0 - ((acos(x0) - sqrt(1 - 0.3 * x0 * x0 * x0)) / (((9 * x0 * x0) / sqrt(20 * (1 - 0.3 * x0 * x0 * x0))) - (1 / sqrt(1 - x0 * x0))));
};
cout << "Приближенное значение x=" << x1 << endl;
return 0;
}