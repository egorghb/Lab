#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstddef>
#include <iostream>
#include <math.h>
using namespace std;
int per(const int* a, int n)
{
    int k = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        k++;
    }
    k = sum / k;
    return k;
}

int per(const char* str)
{
    int k = 0;
    int d = strlen(str);
    for (int j = 0; j <= d; j++) {
        if (isalpha(str[j]))
            k++;
    }

    return k;

}


int main()
{
    // 1
    setlocale(0, "");
    const int n = 10;
    int a[n];
    cout << "Массив: ";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }

    cout << "\n Результат: " << per(a, n) << '\n';

    // 2
    char str[256];

    cout << "Введите строку: ";
    cin.getline(str, 256);
    cout << "Результат: " << per(str) << '\n';
    return 0;
}
