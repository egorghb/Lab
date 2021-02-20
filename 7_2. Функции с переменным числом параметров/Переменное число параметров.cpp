#include <iostream>
#include <cstdlib>
using namespace std;

void prost(int amount, int a...)
{
	int* count = &amount;  // количество интервалов
	int* A = &a;   
	bool isSimple = true;
	for (int k = 1; k <= *count; k++) {  // проходим по всем интервалам
		for (int i = *A; i <= *(A + 1); i++) {  // перебираем все числа внутри интервала
			for (int j = 2; j <= i - 1; j++) {   // проверяем их на простоту
				if (i % j == 0)
					isSimple = false;
			}
			if (isSimple && i > 1)
				cout << i << endl;
			isSimple = true;
		}
		A = (A + 1);   //переносим границу интервала
		cout << endl;
	}
}
int main()
{
	prost(3, 4, 15, 17, 19);
	prost(5, 1, 9, 7, 11, 14, 18);
	prost(6, 1, 7, 11, 16, 20, 25, 30);
	return 0;
}