#include <locale.h>
#include <iostream>
using namespace std;

int n;


struct Queue {
    int data;
    Queue *next;
};


Queue* make_queue(int n, Queue*& first, Queue*& last) {
    if (n == 0)
        return NULL;
    Queue *p = new Queue;
    int a;
    cout << "Введите 1 элемент: ";
    cin >> a;
    p->data = a;
    p->next = NULL;
    first = p;
    last = p;
    for (int i = 2; i <= n; i++) {
        Queue *h = new Queue;
        cout << "Введите " << i << " элемент: ";
        cin >> a;
        h->data = a;
        h->next = p;
        last = h;
        p = last;
    }
    return first;
}

void print_queue(Queue *last) {
    Queue *p = last;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int pop(Queue*& first, Queue*& last) {
    Queue *p = last;
    p = last;
    int k = 0;
    while (p != NULL) {
        k++;
        p = p->next;
    }
    p = last;

    if (k == 1) {
        int t = last->data;
        delete p;
        last = NULL;
        first = NULL;
        return t;
    }
    else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        Queue *t = p;
        int e = p->next->data;
        p = p->next;
        t->next = NULL;
        first = t;
        delete p;
        return e;
    }
}

Queue* push(int n, Queue*& last) {
    Queue *p = new Queue;
    p->data = n;
    p->next = last;
    last = p;
    return last;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите количество элементов: ";
    cin >> n;
    while (n < 1) {
        cout << "Очередь не может быть создана! Введите размер ещё раз: ";
        cin >> n;
    }

    Queue *first, *last;
    make_queue(n, first, last);

    cout << "Ваша очередь: " << endl;
    print_queue(last);
    
    int *arr = new int[n];
    int i = 0;
    while (i < n) {
        int t = pop(first, last);
        if (t % 2 != 0) {
            arr[i] = t;
            i++;
        }
        else {
            n--;
        }
    }
    for (int i = 0; i < n; i++) {
        push(arr[i], last);
    }

    cout << "Ваша очередь после удаления: " << endl;
    print_queue(last);

    return 0;
}
