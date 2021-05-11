#pragma once
#include "Vector.h"
#include "Event.h"
class Dialog :
    public Vector
{
public:
    Dialog(int);
public:
    virtual ~Dialog(void);
    virtual void GetEvent(TEvent& event);
    virtual int Execute(); // main event loop
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);
    int Valid(); //check an attribute "End State"
    void EndExec();
protected:
    int EndState;
};

