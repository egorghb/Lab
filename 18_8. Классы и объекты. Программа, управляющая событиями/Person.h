#pragma once
#include "Object.h"
#include "Event.h"

class Person :
    public Object
{
public:
    Person(void);
public:
    virtual ~Person(void);
    void show();
    void input();
    Person(string, int);
    Person(const Person&);
    //selectors
    string get_name() { return name; }
    int get_age() { return age; }
    //modificators
    void set_name(string);
    void set_age(int);
    Person& operator= (const Person&);
    void HandleEvent(const TEvent& e);
protected:
    string name;
    int age;
};

