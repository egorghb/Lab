#include "Object.h"
#include "Person.h"
#include "Emloyee.h"
#include "Vector.h"
#include "Dialog.h"

int main()
{
    /*Person* p = new Person;
    p->input();
    p->show();

    Emloyee* e = new Emloyee;
    e->input();
    e->show();


    Vector v(10);
    v.add();
    v.add();
    v.show();
    v.del();
    cout << "\nVector size =" << v();*/

    Dialog D(10);
    D.Execute();
    return 0;
}
