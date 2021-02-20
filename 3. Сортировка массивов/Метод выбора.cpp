#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n <= 0) {  // проверка на дурака
        cin >> n;
    }
    int a[100];  
    for (int i = 0; i < n; i++) {   // инициализируем массив
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {   // проходим по массиву n - 1 раз
        int min = a[i];   // переменная для хранения минимального значения
        int imin = i;   // переменная для хранения индекса мин. значения
        for (int j = (i + 1); j < n; j++) {
            if (a[j] < min) {  // находим мин. элемент
                min = a[j];
                imin = j;
            }
        }
        a[imin] = a[i];  // сортируем массив
        a[i] = min;
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}