#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    const int size = 255;
    setlocale(LC_ALL, "Russian");
    string s[size];
    cout << "Введите количество слов: ";
    cin >> n;
    int count[size] = {};
    cout << "Введите текст: " << endl;
    for (int i = 0; n > i; i++) {
        cin >> s[i];
    }
    for (int i = 0; n > i; i++) {
        for (int j = 0; n > j; j++) {
            if (s[i] == s[j] && i != j) {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            cout << s[i] << "\t";
        }
    }
    return 0;
}
