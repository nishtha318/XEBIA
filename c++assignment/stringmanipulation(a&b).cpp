#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str;
    string temp = " ";

    cout << "Enter any string : " << endl ;
    getline(cin , str);

    for(int i = str.length() - 1 ; i >= 0 ; i-- )
    {
        temp += str[i];

    }

    cout << "reversed string is :" << temp << endl;

    if (temp == str)
    {
        cout << "the string is  a palindrome" << endl;
    }
    else
    {
        cout << "the string is not a palindrome" << endl;
    }


}
