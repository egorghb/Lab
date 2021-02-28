#include <locale.h>
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<char>mylist;


void make(int n) {
    char tmp;
    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> tmp;
        mylist.push_back(tmp);
    }
}
    
void add(int size) {
    int n;
    char k;
    cout << endl << "Введите номер элемента, который нужно добавить: ";
    cin >> n;
    while (n <= 0 || n > size) {
        cout << "Неверный номер! Введите ещё раз: ";
        cin >> n;
    }
    cout << "Введите этот элемент: ";
    cin >> k;
    list<char> ::iterator it;
    it = mylist.begin();
    advance(it, n - 1);
    mylist.insert(it, k);
}


int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    
    cout << "Введите количество элементов: ";
    cin >> size;
    while (size < 1) {
        cout << "Список не может быть создан. Введите ещё раз: ";
        cin >> size;
    }
    make(size);
    cout << "Ваш список: " << endl;
    copy(mylist.begin(), mylist.end(), ostream_iterator<char>(cout, " "));

    add(size);
    copy(mylist.begin(), mylist.end(), ostream_iterator<char>(cout, " "));


    return 0;
}
