#include <locale.h>
#include <iostream>
using namespace std;

struct List {
    char *data = new char;
    List *next;
    List *prev;
};


List* make(int size) {
    if (size == 0) {
        cout << "Список не может быть создан!" << endl;
        exit(0);
    }
    List *first, *p;
    first = NULL;
    p = new List;
    cout << "Введите 1 элемент: ";
    cin >> p->data;
    first = p;
    p->next = NULL;
    p->prev = NULL;
    for (int i = 2; i <= size; i++) {
        List *h = new List;
        List *q = p;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        cin >> p->data;
        p->next = NULL;
        p->prev = q;
    }
    return first;
}


void print(List *first) {
    if (first == NULL)
        cout << "Список пустой." << endl;
    else {
        List *p = first;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}


void add(List* first, int size) {
    int n;
    char* k = new char;
    cout << "Введите номер элмента, который нужно добавить: ";
    cin >> n;

    while (n <= 0 || n > size) {
        cout << "Неверный номер! Введите ещё раз: ";
        cin >> n;
    }

    cout << "Введите этот элемент: ";
    cin >> k;

    List *p = first;

    while (p->next != NULL) {
        p = p->next;
    }
    
    List *h = new List;
    h->next = NULL;
    h->prev = p;
    p->next = h;
    p = p->next;

    for (int i = size + 1; i > n; i--) {
        p->data = p->prev->data;
        p = p->prev;
    }
    
    p->data = k;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    
    cout << "Введите размер списка: ";
    cin >> size;

    List *list = make(size);
    cout << "Ваш список: " << endl;
    print(list);

    add(list, size);
    print(list);

    return 0;
}