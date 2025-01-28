#include<iostream>
using namespace std;

int main()
{
    string s = "abcd";
    string temp = " ";
    int i;
    for(i = 3 ; i >= 0 ; i--){
        temp += s[i];
    }
    cout << "reversed string is:" << temp << endl;
    return 0;

}