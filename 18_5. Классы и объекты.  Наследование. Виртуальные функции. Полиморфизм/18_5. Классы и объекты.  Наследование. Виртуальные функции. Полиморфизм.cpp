#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Vector v(5);
    Person a;
    cin >> a;

    Student b;
    cin >> b;
    cout << b << endl;
    cout << a << endl;

    Object* p = &b;
    p->Show();
    p = &a;
    p->Show();

    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v;
    return 0;
}
