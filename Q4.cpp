#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float a,b;
    cout<<"enter two floating point numbers:";
    cin >> a >> b;

    cout << "division of both numbers is : " << fixed << setprecision(2) << a / b;
    return 0;
}