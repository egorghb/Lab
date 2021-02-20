#include <iostream>
#include <cmath>
using namespace std;
float Pi(float n, float sum, float x)
{
    if (n > 0)
    {
        sum += pow(-1, n - 1) * pow(x, n) / n;
        n--;
        return Pi(n, sum, x);
    }
    else return sum;
}
int main()
{
    float n;
    float sum = 0, x;
    cout << "n=" << endl;
    cin >> n;
    cout << "x=" << endl;
    cin >> x;
    cout << "y=ln(1+x):=" << Pi(n, sum, x);
    return 0;
}