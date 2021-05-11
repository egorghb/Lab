#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef priority_queue<Pair> Queue;
typedef list<Pair> List;

Queue make_queue(int n) {
    Queue q;
    Pair p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        q.push(p);
    }
    return q;
}

List copy_queue_to_list(Queue q) {
    List l;
    while (!q.empty()) {
        l.push_back(q.top());
        q.pop();
    }
    return l;
}

Queue copy_list_to_queue(List l) {
    Queue q;
    list<Pair>::iterator it = l.begin();
    for (; it != l.end(); it++)
        q.push(*it);
    return q;
}

void print_queue(Queue q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

Pair average(Queue q) {
    List l = copy_queue_to_list(q);
    int n = 1;
    Pair sum = q.top();
    q.pop();
    while (!q.empty()) {
        sum = sum + q.top();
        q.pop();
        n++;
    }
    q = copy_list_to_queue(l);
    return sum / n;
}

void add_to_queue(Queue& q, Pair& k) {
    List l;
    Pair p;
    l.push_back(k);
    while (!q.empty()) {
        p = q.top();
        l.push_back(p);
        q.pop();
    }
    q = copy_list_to_queue(l);
}

void del_queue(Queue& q, int first, int last) {
    List l = copy_queue_to_list(q);
    List::iterator it1 = l.begin(), it2 = l.begin();
    advance(it1, q.size() - first);
    advance(it2, q.size() - last - 1);
    l.erase(it2, it1);
    q = copy_list_to_queue(l);
}

void substr_queue(Queue& q, Pair& p) {
    List l = copy_queue_to_list(q);
    List::iterator it = l.begin();
    for (; it != l.end(); it++)
        *it = *it - p;
    q = copy_list_to_queue(l);
}

int main()
{
    Pair p;
    Queue q;
    int n;
    cout << "N = "; cin >> n;
    q = make_queue(n);
    print_queue(q);
    p = average(q);
    cout << "Average: " << average(q) << endl;
    cout << "Adding average... " << endl;
    add_to_queue(q, p);
    print_queue(q);
    int first = -1, last = -1;
    while (first < 0 || first > q.size() || last < 0 || last > q.size()) {
        cout << "\nElements from which range to remove?";
        cout << "\nFirst position: "; cin >> first;
        cout << "Last position: "; cin >> last;
    }
    del_queue(q, first, last);
    print_queue(q);
    cout << "\nSubstracting the arithmetic mean...\n";
    p = average(q);
    substr_queue(q, p);
    print_queue(q);
    cout << endl;
    system("pause");
    return 0;
}
