#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstdlib>

using namespace std;

void count(string& last_row) {
    int k = 0;
    int length = last_row.length();
    for (int i = 0; i < length; i++) {
        if (last_row[i] == ' ') {
            k++;
        }
    }
    cout << k + 1 << " ����(�)" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");

    ifstream input;
    input.open("F1.txt");

    ofstream output;
    output.open("F2.txt");

    int N1, N2, i_now = 0;
    string row, row1;

    cout << "������� ����� ��������� ������: ";
    cin >> N1;
    cout << "������� ����� �������� ������: ";
    cin >> N2;

    while (N1 <= 0 or N2 <= 0 or N1 > 10 or N2 > 10) {
        cout << "������������ ����� ������. ������� ��� ���: ";
        cin >> N1 >> N2;
    }

    if (input.is_open() && output.is_open()) {

        while (!input.eof()) {
            i_now++;
            getline(input, row);
            if (i_now > N1 && i_now < N2 && (row[0] == 'A' or row[0] == 'a')) {
                output << row << '\n';
                row1 = row;
            }
        }

        if (N2 + 3 >= 10) {
            count(row1);
        }
        else {
            i_now = 0;
            input.close();
            ifstream input;
            input.open("F1.txt");

            while (!input.eof()) {
                i_now++;
                getline(input, row);
                if (i_now > N2 + 3)
                    output << row << '\n';
            }
            count(row);
        }
    }
    else
        cout << "������! ����(�) �� ������(�)\n";

    input.close();
    output.close();

    return 0;
}