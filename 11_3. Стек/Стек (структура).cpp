#include <iostream>
using namespace std;

int a;

struct Stack {
    int data;
    Stack* prev;
};


Stack* make_stack(int n) {
    Stack* top, * p;
    top = NULL;
    p = new Stack;
    cin >> a;
    p->data = a;
    p->prev = NULL;
    top = p;
    for (int i = 2; i <= n; i++) {
        Stack* h = new Stack;
        cin >> a;
        h->data = a;
        h->prev = top;
        top = h;
    }
    return top;
}


void print(Stack* top) {
    if (top == NULL)
        cout << "Стек пуст.\n";
    else {
        Stack* p = top;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}

int pop(Stack*& top) {
    Stack* p = top;
    int k = 0;
    while (p != NULL) {
        k++;
        p = p->prev;
    }
    p = top;
    if (k == 1) {
        int t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else {
        Stack* t = p->prev;
        int u = p->data;
        top = t;
        delete p;
        return u;
    }
}


Stack* push(Stack*& top, int m) {
    Stack* p = new Stack;
    p->data = m;
    p->prev = top;
    top = p;
    return top;
}



int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите количество элементов: ";
    int n, e = 0;
    cin >> n;
    cout << "Введите элементы стека:\n";
    Stack* st = make_stack(n);
    cout << "Стек:\n";
    print(st);

    Stack* st2 = NULL;

    for (int i = 0; i < n; i++) {
        int m = pop(st);
        if (m % 2 != 0)
            push(st2, m);
        else
            e = e + 1;
    }
    n = n - e;
    for (int i = 0; i < n; i++) {
        int m = pop(st2);
        push(st, m);
    }
    cout << "Обновленный стек:\n";
    print(st);
    return 0;
}
