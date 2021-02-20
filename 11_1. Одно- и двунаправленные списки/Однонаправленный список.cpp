#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;


struct List {
	int data;
	List* next;
};



List* make(int size) {
	if (size <= 0) {
		cout << "Список не может быть создан!" << endl;
		exit(0);
	}
	List *first, *p;
	first = NULL;
	cout << "Введите 1 элемент: ";
	p = new List;
	cin >> p->data;
	first = p;
	p->next = NULL;

	for (int i = 2; i <= size; i++) {
		List *h = new List;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << " элемент: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

void print(List *first) {
	if (first == NULL)
		cout << "Список пуст\n";
	else {
		List *p = first;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

List* del(List *first) {
	bool f = 1;
	List *p = first;
	while (f && ((p->data) % 2 == 0)) {
		List *q = first;
		if (p->next != NULL)
			first = p->next;
		else {
			first = NULL; 
			f = 0;
		}
		delete q;
		p = first;
	}
	while (f && (p->next != NULL)) {
		if ((p->next->data) % 2 == 0) {
			List *q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else p = p->next;
	}
	return first;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите количество элементов списка: ";
	cin >> size;
	List *list = make(size);
	print(list);
	List *list1 = del(list);
	print(list1); 

    return 0;
}

