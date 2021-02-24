#include <locale.h>
#include <iostream>
#include <stack>
using namespace std;

int n;

void make(stack<char>& st) {
    char a;    // символ в стеке
    cout << "Введите размер стека: ";
    cin >> n;
    while (n < 1) {
        cout << "Стек невозможно создать! Введите ещё раз: ";
        cin >> n;
    }
    for (int i = 1; i <= n; i++) {
        cout << "Введите " << i << " элемент: ";
        cin >> a;
        st.push(a);
    }
    cout << endl;
}


void print(stack<char> &stRef) {
    int p = stRef.size();
    if (p == 0) {
        cout << "Стек пуст." << endl;
    }
    else {
        for (int i = 0; i < p; i++) {
            cout << stRef.top() << " ";
            stRef.pop();
        }
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    
    stack<char> st; // Объявляем стек
    stack<char> st2; // объявляем 2 стек для переноса неудаленных элементов

    make(st);
    cout << "Ваш стек: " << endl;
    print(st);

    
    char b;
    int k;     // номер этого символа
    cout << "Введите номер символа, который надо добавить: " << endl;
    cin >> k;
    while (k < 1 || k > n) {
        cout << "Неправильный номер! Введите ещё раз: " << endl;
        cin >> k;
    }
    cout << "Введите этот символ: " << endl;
    cin >> b;
    for (int i = 0; i < n - k + 1; i++) {
        st2.push(st.top());
        st.pop();
    }
    cout << "1" << endl;
    st.push(b);
    cout << "2" << endl;
    for (int i = 0; i < n - k + 1; i++) {
        st.push(st2.top());
        st2.pop();
    }


    cout << "Ваш стек после добавления элемента: " << endl;
    print(st);

    return 0;
}

