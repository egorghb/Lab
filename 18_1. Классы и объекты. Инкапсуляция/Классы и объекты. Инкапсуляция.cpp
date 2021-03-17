#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S) {
    fraction t;
    t.Init(F, S);
    return t;
}


int main()
{
    fraction A;
    fraction B;
    A.Init(3.0, 2);
    B.Read();
    A.Show();
    B.Show();

    cout << "A.Summa(" << A.first << ", " << A.second << ") = " << A.Summa() << endl;
    cout << "B.Summa(" << B.first << ", " << B.second << ") = " << B.Summa() << endl;

    fraction* X = new fraction;
    X->Init(2.0, 5);
    X->Show();
    X->Summa();
    cout << "X.Summa(" << X->first << ", " << X->second << ") = " << X->Summa() << endl;

    fraction mas[3];
    for (int i = 0; i < 3; i++) 
        mas[i].Read();
    for (int i = 0; i < 3; i++)
        mas[i].Show();
    for (int i = 0; i < 3; i++) {
        mas[i].Summa();
        cout << "mas[" << i << "].Summa(" << mas[i].first << ", " << mas[i].second << ") = ";
        cout << mas[i].Summa() << endl;
    }

    fraction* p_mas = new fraction[3];
    for (int i = 0; i < 3; i++)
        p_mas[i].Read();
    for (int i = 0; i < 3; i++)
        p_mas[i].Show();
    for (int i = 0; i < 3; i++) {
        p_mas[i].Summa();
        cout << "p_mas[" << i << "].Summa(" << p_mas[i].first << ", " << p_mas[i].second << ") = ";
        cout << p_mas[i].Summa() << endl;
    }

    double y;
    int z;
    
    cout << "first? ";
    cin >> y;
    cout << "second? ";
    cin >> z;

    fraction F = make_fraction(y, z);
    F.Show();

    return 0;
}

