#include <iostream>
using namespace std;

double summa(double a[100][100], int n, int m)
{
    double sum;
    double sum1 = 0;
    int i1 = 1, j1 = 1;
    sum = a[0][0] + a[1][0] + a[2][0] + a[0][1] + a[1][1] + a[2][1] + a[0][2] + a[1][2] + a[2][2];
    for (int j = 1; j < m - 1; j++) {
        for (int i = 1; i < n - 1; i++) {
            for (int k = j - 1; k <= j + 1; k++) {
                for (int l = i - 1; l <= i + 1; l++) {
                    sum1 = sum1 + a[l][k];
                }
            }
            if (sum1 > sum) {
                sum = sum1;
                j1 = j;
                i1 = i;
            }
            sum1=0;
        }
    }
    cout << sum << "\n\n";
    for (int j = j1 - 1; j <= j1 + 1; j++) {
        for (int i = i1 - 1; i <= i1 + 1; i++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int m,n;
    cout << "Введите количество столбцов массива: ";
    cin >> n;
    cout << "Введите количество строк массива: ";
    cin >> m;
    while (m < 3 || n < 3) {
        cout << "Введите n и m заново:  ";
        cin >> n;
        cin >> m;
    }
    double a[100][100];  // объявляем массив
    for (int i = 0; i < n; i++) {    //вводим каждый элемент массива
        for (int j = 0; j < m; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    summa(a, n, m);
	return 0;
}