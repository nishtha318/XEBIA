#include <iostream>
using namespace std;

class Student
{
   string name;
   int roll_no;
   public:


   void input()
   {
    cout << "enter your name " << endl ;
    cin >> name;

    cout << "enter roll no " << endl;
    cin >> roll_no;
   }


   void display()
   {
    cout << "name is " << name << endl;
    cout << "roll no is " << roll_no << endl;

   }

};

int main()
{
    Student s1;
    s1.input();
    s1.display();
}