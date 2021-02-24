#include <locale.h>
#include <iostream>
#include <queue>
using namespace std;

queue<int>qu;

void add(int n) {
    cout << "Введите " << n << " элементов" << endl;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        qu.push(a);
    }
}


void print() {
    int p = qu.size();
    int *arr = new int[p];
    for (int i = 0; i < p; i++) {
        arr[i] = qu.front();
        cout << qu.front() << " ";
        qu.pop();
    }
    for (int i = 0; i < p; i++) {
        qu.push(arr[i]);
    }
    cout << endl;
}


void delete_qu(int n) {
    int j = 0;
    int *arr = new int[n];
    while (j < n) {
        if (qu.front() % 2 == 0) {
            qu.pop();
            n--;
        }
        else {
            arr[j] = qu.front();
            qu.pop();
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        qu.push(arr[i]);
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;

    cout << "Введите размер: ";
    cin >> n;
    while (n <= 0) {
        cout << "Очередь не может быть создана! Введите размер ещё раз: ";
        cin >> n;
    }

    add(n);
    
    cout << "Ваша очередь: " << endl;
    print();

    delete_qu(n);

    cout << "Очередь после удаления: " << endl;
    print();

    return 0;
}
