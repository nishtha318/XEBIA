#include <iostream>
using namespace std;

int reverseNumber(int n);
bool isPalindrome(int result, int n);

int main()
{
    int n;
    cin >> n;

    int result = reverseNumber(n);
    bool palindrome = isPalindrome(result , n);
    cout << palindrome ;
    
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

bool isPalindrome(int result , int n)
{
    if ( result == n)
    {
        return true ; 
    }
    else
    {
        return false;
    }

}