#include <iostream>
using namespace std;

class Base
{
    public:
    virtual void display()
    {
        cout << "display method of base class" << endl;
    }
};


class Derived : public Base
{
    public:
    virtual void display() override
    {
        cout << "display method of derived class" << endl;
    }
};

int main()
{
    Base* baseptr;
    Base base;
    Derived derivedobj;
    
    baseptr = &derivedobj;
    

    baseptr -> display();


}

