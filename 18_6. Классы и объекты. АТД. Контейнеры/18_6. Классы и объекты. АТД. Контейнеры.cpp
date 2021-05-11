#include "List.h"

int main()
{
    List a(5);
    cout << a << "\n";
    cin >> a;
    cout << a << "\n";
    List b(10);
    cout << b << "\n";
    List c(10);
    c = b + 100;
    cout << c << "\n";
    cout << "\nthe length of a = " << a() << endl;

    cout << *(a.first()) << endl;
    Iterator i = a.first();
    i++;
    cout << *i << endl;
    for (i = a.first(); i != a.last(); i++)
        cout << *i << " " << endl;
    return 0;
}
