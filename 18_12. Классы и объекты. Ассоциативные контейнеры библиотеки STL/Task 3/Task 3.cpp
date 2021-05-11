#include <iostream>
#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
#include "List.h"
using namespace std;

int main()
{
    int n;
    cout << "N = "; cin >> n;
    Container<Pair> m(n);
    m.print();
    Pair k = m.average();
    cout << "Average = " << k << endl;
    m.add(k);
    m.print();
    int first, last;
    cout << "\nElements with keys from which range to remove?";
    cout << "\nFirst position: "; cin >> first;
    cout << "Last position: "; cin >> last;
    m.del(first, last);
    m.print();
    cout << "\nSubstracting the arithmetic mean...\n";
    k = m.average();
    cout << "Average = " << k << endl;
    m.substr(k);
    m.print();
    system("pause");
    return 0;
}
