#include <iostream>
using namespace std;

bool is_prime(int n);
int next_prime(int n);
void factors(int n);

int main()
{
    int n; 
    cout << "enter any number:" << endl;
    cin >> n;


    bool prime_no = is_prime(n);
    if(prime_no == true)
    {
        cout << n << " " << "is a prime number" << endl;
        cout << "next greater prime number is" << " " << next_prime(n) << endl;
    }
    else
    {
        cout << n << " " << "is not a prime number " << endl;
        factors(n);
        cout << " " << "are the factors" << endl;

    }

}

bool is_prime(int n)
{
    if( n <= 1 )
    {
        return false;
    }

    for(int i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true ;
}


int next_prime(int n)
{
    int next = (n % 2 == 0) ? n + 1 : n + 2 ;

    while(is_prime(next) == false)
    {
        next += 2;
    }

    return next ;
    
}

void factors(int n)
{
    for(int i = 1 ; i <= n ; i++)
    {
        if(n % i == 0 )
        {
            cout << i << " " ;
        }
    }
}

