#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
#include <iostream>
#include <queue>
#include <list>
#include "List.h"
using namespace std;

int main()
{
    List<Pair>l(3);
    l.print();
    Pair p = l.average();
    cout << "\nAverage = " << p << endl;
    cout << "Adding average..." << endl;
    l.add(p);
    l.print();
    int first = -1, last = -1;
    while (first < 0 || first > l() || last < 0 || last >l()) {
        cout << "\nElements from which range to remove?";
        cout << "\nFirst position: "; cin >> first;
        cout << "Last position: "; cin >> last;
    }
    l.del(first, last);
    l.print();
    cout << "\nSubstracting the arithmetic mean...\n";
    l.substr();
    l.print();
    cout << endl;
    system("pause");
    return 0;
}
