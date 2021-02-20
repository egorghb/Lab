#include <iostream>
#include <math.h>
using namespace std;
double f(double x)
{
    return acos(x) - sqrt(1 - 0.3 * x * x * x);
}

int main() {
    double e, a, b, x0, x1, lam;
    lam = -1;
    e = 0.000001;
    a = 0;
    b = 1;
    x1 = (a + b) / 2;
    do {
        x0 = x1;
        x1 = x0 - lam * f(x0);
    } while (fabs(x1 - x0) > e);
    cout << x1 << endl;
    return 0;
}