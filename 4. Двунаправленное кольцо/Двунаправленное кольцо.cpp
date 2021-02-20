#include <iostream>
using namespace std;

int main() {
    int n, k;
    k = -1;
    cout << "Input lenght array: ";
    cin >> n;   // вводим длину массива
    int a[100];  // объявляем массив
    for (int i = 0; i < n; i++) {    //вводим каждый элемент массива
        cin >> a[i];
    }
    while ((k < 1) || (k >= n)) {       // проверка на дурака
        cout << "Input K: ";
        cin >> k;   // вводим номер элемента, с которого начнется кольцо
    }
    for (int i = k; i >= 0; i--) {  // выводим первую часть кольца
        cout << a[i] << " ";
    }
    for (int i = n - 1; i >= (k - 1); i--) {  // выводим оставшуюся часть кольца
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = n + 1; i > 0; i--) {
        a[i] = a[i - 1];   // смещаем массив на одну ячейку вправо
    }
    n = n + 2; 
    cout << "Input a[0]: ";
    cin >> a[0];  // вводим первый элемент массива
    cout << "Input a[n-1]: ";
    cin >> a[n - 1];   // вводим послдний элемент
    for (int i = k; i < n; i++) {   // выводим первую часть кольца
        cout << a[i] << " ";
    }
    for (int i = 0; i <= (k + 1); i++) {  // выводим оставшуюся часть кольца
        cout << a[i] << " ";
    }
    return 0;
}