#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int n;
    cin >> n;

    int result = factorial(n);
    cout << result ;

}

int factorial(int n)
{
    int p = 1;
    for( int i = n ; i > 0 ; i--)
    {
        p *= i ;
        
    }

    return p;
}
