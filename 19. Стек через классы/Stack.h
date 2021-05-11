#pragma once
#include <iostream>
#include <stack>
using namespace std;

class Stack
{
	stack<int> st;
	stack<int> st2;
public:
	void make(int);
	void print();
	void del();
	void push();
};

