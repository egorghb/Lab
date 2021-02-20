﻿#include <iostream>
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
    for (int i = 1; i < n; i++) {  // проходим по массиву, начиная со 2 элемента
        int j = i - 1;   // присваиваем j номер предыдущего элемента перед a[i]
        int y = a[i];    // присваиваем y сравниваемый элемент массива
        bool f = false;  // инициализируем флажок
        while ((j >= 0) && (!f)) {
            if (a[j] > y) {   // проверяем условие
                a[j + 1] = a[j];   // перемещаем элемент массива на 1 вправо
                j = j - 1;   // переходим к предыдущему элементу
            }
            else {
                f = true;  // меняем значение флажка, так как нашли нужный элемент массива
            }
            a[j + 1] = y;   // ставим элемент массива в нужное место
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}