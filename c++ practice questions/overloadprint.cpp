#include <iostream>
using namespace std;

void print(string s);
void print(int n);
void print(string s , int n );

int main()
{
    print("hello");
    print(5);
    print("hello" , 5);
}

void print(string s)
{
    cout << s << endl;
}

void print(int n)
{
    cout << n << endl;
}

void print (string s , int n)
{
    cout << s << " " << n << endl;
}