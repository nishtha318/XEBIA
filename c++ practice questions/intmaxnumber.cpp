#include <iostream>
using namespace std; 

int maxNumber(int a , int b);

int main()
{
    int result;
    int a , b ;
    cin >> a >> b ;


    if(a == b)
    {
        cout << "numbers are equal" << endl ;
    }

    else
    {
        cout << maxNumber(a ,b) << endl;
    }

}


int maxNumber(int a , int b )
{
    
    if(a == b)
    {
        return 0 ; 
    }

    return ( a > b) ? a : b ;
}