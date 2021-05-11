#include "List.h"
#include "Pair.h"
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите список из 5 элементов: ";
    List<int>A(5, 0);                 //инициализация, 
    cin >> A;                         //ввод 
    cout << A << endl;                //и вывод значений списка
    List<int>B(10, 1);                //инициализация
    cout << B << endl;                //и вывод значений списка
    B = A;                            //операция присваивания
    cout << B << endl;
    cout << A[2] << endl;             //доступ по индексу
    cout << "size = " << A() << endl; //получение длины списка
    B = A + 10;                       //операция сложения с константой 
    cout << B << endl;
    Pair p;
	cin >> p;
	cout << p;
    int k;
    cout << "\nk =  ";
    cin >> k;
    Pair tmp(k, k);
    Pair p2;
    p2 = p + tmp;
    cout << p2;
    //------------------test user's class----------
    Pair p3;
    cin >> p3;
    cout << p3 << endl;
    List<Pair>C(5, p3);
    cin >> C;
    cout << C << endl;
    
    List<Pair>D(10, p3);
    cout << D << endl;

    D = C;

    cout << D << endl;
    cout << C[2] << endl;
    cout << "size = " << C() << endl;

    D = C + p3;
    cout << D << endl;
    return 0;
}
