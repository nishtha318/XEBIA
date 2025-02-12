#include <iostream>
using namespace std;

void swap(int &x , int &y);

int main()
{
    int a = 10 , b = 20 ;


    cout << "values before swap  " << a << " " << b << endl;
    swap(a,b);
    cout << "values after swap  " << a  << " " << b ;



}

void swap(int &x , int &y)
{
    int temp = x;
    x = y ;
    y = temp ;
}

