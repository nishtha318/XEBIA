#include <iostream>
using namespace std;

int reverseNumber(int n);

int main()
{
    int n;
    cin >> n;

    int result = reverseNumber(n);
    cout << result << endl;
}

int reverseNumber(int n)
{
    int temp, rev = 0 ;
    while (n!= 0)
    {
        temp = n % 10 ;
        rev = rev * 10 + temp;
        n = n / 10 ;
    }
    return rev ;
}