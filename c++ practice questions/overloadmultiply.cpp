#include <iostream>
using namespace std;

int multiply (int a , int b);
double multiply(int a , double b );
float multiply(float a , float b , float c);

int main()
{
    cout << multiply(5 , 4) << endl;
    cout << multiply(5 , 1.2) << endl;
    cout << multiply(3.4 , 2.2 , 1.5) << endl;

    return 0;
}

int multiply(int a , int b)
{
    return a * b ;
    
}

double multiply(int a , double b)
{
    return float(a) * b;
}

float multiply (float a , float b , float c)
{
    return a * b * c;
}

