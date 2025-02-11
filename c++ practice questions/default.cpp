#include <iostream>

using namespace std;

string name(string a = "guest" , string b = "" , string c = "");

int main()
{
    cout << name() << endl;
    cout << name("riya" , "sethi") << endl;
    cout << name("riya") << endl;
    return 0;


}

string name(string a , string b , string c)
{
    return "welcome " + a + " " + b + " " + c;
}