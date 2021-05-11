#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
#include "List.h"
#include <iostream>

int main()
{
    List<Pair> list(5);
    list.print();

    Pair s = list.average();
    cout << "\nAverage = " << s << endl;
    int pos;
    cout << "\nPosition = "; cin >> pos;
    list.add(s, pos);
    list.print();
    int first = -1, last = -1;
   
    while (first < 0 || first > list() || last < 0 || last > list()) {
        cout << "\nElements from which range to remove?";
        cout << "\nFirst position: "; cin >> first;
        cout << "Last position: "; cin >> last;
    }
    list.del(first, last);
    list.print();
    s = list.average();
    cout << "\nAverage = " << s << endl;
    cout << "\nSubstracting the arithmetic mean...\n";
    list.substraction(s);
    list.print();
    cout << endl;
    system("pause");
    return 0;
}
