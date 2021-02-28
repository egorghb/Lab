#include <iostream>
#include <stack>
using namespace std;
int a;
void print(stack<int> st)
{
	int p = st.size();
	if (p == 0)
	{
		cout << "стек пустой";
	}
	else {
		for (int i = 0; i < p; i++)
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}
int main()
{
	setlocale(0, "rus");
	stack<int> st;
	int n;
	cout << "введите количество элементов стека: ";
	cin >> n;
	cout << "введите элементы стека: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
	}
	cout << "стек: ";
	print(st);
	stack<int> st2;
	for (int i = 0; i < n; i++)
	{
		if (st.top() % 2 != 0)
		{
			st2.push(st.top());
		}
		st.pop();
	}
	n = st2.size();
	for (int i = 0; i < n; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
	cout << "обновленный стек: ";
	print(st);
	return 0;
}
