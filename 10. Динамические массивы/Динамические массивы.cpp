#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

const string alph = "abcdefghijklmnopqrstuvwxyz";

void make_array(string* array, int n) {
    string tmp;
    int k;
    for (int i = 0; i < n; i++) {
        k = rand() % 10 + 1;
        for (int j = 0; j < k; j++) {
            tmp = tmp + alph[rand() % 26];
        }
        array[i] = tmp;
        tmp = {};
    }
}

void delete_string(string* array, int n) {
    int count = 0;
    int i_delete;
    for (int i = 0; i < n; i++) {
        if (array[i].length() > count) {
            count = array[i].length();
            i_delete = i;
        }
    }

    for (int i = i_delete; i < n - 1; i++) {
        array[i] = array[i + 1];
    }

    string* new_array = new string[n - 1];

    for (int i = 0; i < n - 1; i++) {
        new_array[i] = array[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cout << new_array[i] << endl;
    }
    delete[] new_array;
}

void print(string* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите n: ";
    cin >> n;

    string* array = new string[n];

    make_array(array, n);
    print(array, n);
    cout << "----------------" << endl;
    delete_string(array, n);

    delete[] array;

    return 0;
}