#include <iostream>
using namespace std;

int sumOfDigits(int n);

int main()
{
    int n;
    cin >> n;

    int result = sumOfDigits(n);
    cout << result;

}

int sumOfDigits(int n)
{
    int sum = 0;
    while( n != 0)
    {
        int temp = n % 10;
        sum += temp;
        n = n / 10 ;

    }

    return sum;
}

