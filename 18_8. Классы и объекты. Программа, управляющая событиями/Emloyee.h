#pragma once
#include "Person.h"

class Emloyee :
    public Person
{
public:
    Emloyee(void);
public:
    ~Emloyee(void);
    void show();
    void input();
    Emloyee(string, int, float, string);
    Emloyee(const Emloyee&);
    float get__rating() { return rating; }
    string get_group() { return position; }
    void set_rating(float);
    void set_position(string);
    Emloyee& operator= (const Emloyee&);
protected:
    float rating;
    string position;
};

