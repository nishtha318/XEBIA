#include<iostream>
using namespace std;
int main()
{
    string name;
    int age;

    cout << "enter your name:" <<endl;
    getline(cin , name);
    cout <<"enter your age:" << endl;
    cin >> age;
    
    cout <<"Hello" << " " << name << " " << "you are" << " " << age << " " << "years old" << endl;
    return 0;

}