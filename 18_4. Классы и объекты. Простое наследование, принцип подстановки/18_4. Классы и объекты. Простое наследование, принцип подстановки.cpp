#include "Person.h"
#include "Student.h"

void f1(Person& p)
{
    p.set_name("Gena");
    cout << p;
}

Person f2()
{
    Student s("Aleksey", 12, 4);
    return s;
}

int main()
{
    Person a;
    cin >> a;
    cout << a;
    Person b("Vasya", 13);
    cout << b;
    a = b;
    cout << a;
    Student c;
    cin >> c;
    cout << c;
    f1(c);
    a = f2();
    cout << a;
    return 0;
}

