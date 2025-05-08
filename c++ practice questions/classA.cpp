#include <iostream>
using namespace std;

class A
{
    int V1 ;

    protected:
    int V2;

    public:

    //non parameterized constructor 
    A(): V1(0),V2(0)
    {
        cout << " A constructor is called " << endl;
    }

    //parmeterized constructor
    A(int a, int b) : V1(a), V2(b)
    {}

    ~A()
    {
        cout << "A is destroyed" << endl;
    } 

    void displayA()
    {
        cout << V1 << endl << V2 << endl;
    }

};


class B : public A
{
    int X1;

    protected:
    int X2;

    public:

    B(int a , int b) : X1(a) , X2(b)
    {
        cout << "B constructor is called " << endl;
    }


    ~B()
    {
        cout <<"B is destroyed"<< endl;
    }

    void displayB()
    {
        cout << X1 << endl << X2 << endl;
    }


};

int main()
{
    B b1(100,200);
    b1.displayA();
    b1.displayB();

    return 0;
}