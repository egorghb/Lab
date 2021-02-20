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
    for (int i = 0; i < n - 1; i++) {  // проходим по массиву n - 1 раз, начиная со 2 элемента
        for (int j = n - 1; j >= (i + 1); j--) {  // проходим по массиву, в обратную сторону
            if (a[j - 1] > a[j]) {  // сравниваем два соседних элемента и меняем их местами
                int r = a[j];
                a[j] = a[j - 1];
                a[j - 1] = r;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}