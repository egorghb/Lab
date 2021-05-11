#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
using namespace std;

typedef priority_queue<Pair> PQueue;
Pair p;

PQueue make_queue(int n) {
    Pair a;
    PQueue q;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << endl;
        cin >> a;
        q.push(a);
    }
    return q;
}

void print_queue(PQueue q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        cout << q.top() << endl;
        q.pop();
    }
    cout << endl;
}

Pair average(PQueue q) {
    Pair p_;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        p_ = p_ + q.top();
        q.pop();
    }
    return p_ / n;
}

list<Pair> copy_queue_to_list(PQueue q) {
    list<Pair> l;
    int n = q.size();
    for (int i = 0; i < n; ++i, q.pop())
        l.push_back(q.top());
    return l;
}

PQueue copy_list_to_queue(list<Pair> l) {
    PQueue q;
    list<Pair>::iterator it = l.begin();
    for (; it != l.end(); it++)
        q.push(*it);
    return q;
}

struct Equal_p {
    bool operator() (const Pair& p_) {
        return p_ == p;
    }
};

void substr(Pair& p_) {
    p_ = p_ - p;
}

PQueue queue_remove_if(PQueue q) {
    list<Pair> l;
    l = copy_queue_to_list(q);
    l.remove_if(Equal_p());
    q = copy_list_to_queue(l);
    return q;
}

PQueue queue_for_each(PQueue q) {
    list<Pair> l;
    l = copy_queue_to_list(q);
    for_each(l.begin(), l.end(), substr);
    q = copy_list_to_queue(l);
    return q;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    PQueue q;
    q = make_queue(n);
    print_queue(q);
    p = average(q);
    cout << "Average = " << p << endl;
    q.push(p);
    print_queue(q);
    cout << "Which element to remove: " << endl;
    cin >> p;
    q = queue_remove_if(q);
    print_queue(q);
    p = average(q);
    cout << "Average = " << p << endl;
    q = queue_for_each(q);
    print_queue(q);
    system("pause");
    return 0;
}