#include<iostream>
using namespace std;
int main()
{
    int a , b;
    char s;

    cout << "enter two numbers:" << endl;
    cin >> a >> b;

    cout << "enter any operator:" << endl;
    cin >> s;

    switch(s){
        case '+' : cout << "sum is : " << a+b ; break;
        case '-' : cout<<"subtraction is : " << a-b ; break;
        case '*' : cout<<"multiplication is : " <<a*b ; break;
        case '/' : cout<<"division is:" << a / b ; break;
        default : cout<<"wrong operator";

    }
    return 0;
    
}