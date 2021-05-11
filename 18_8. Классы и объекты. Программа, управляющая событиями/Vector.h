#pragma once
#include "Object.h"
#include "Emloyee.h"

class Vector
{
public:
	Vector(int);
public:
	~Vector(void);
	void add();
	void del();
	void show();
	int operator() ();
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};

