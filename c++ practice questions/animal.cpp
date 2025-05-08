#include <iostream>
using namespace std;

class Animal
{
    protected:
    string name;
    int age;

    public:
    Animal()
    {
        cout << "animal default constructor called" << endl;
    }

    Animal(string name,int age) : name(name) , age(age)
    {

    }

    ~Animal()
    {
        cout << "animal class destroyed" << endl;
    }

    void eat()
    {
        cout << name << "animal is eating" << endl;
    }

    void sleep()
    {
        cout << name <<"animal is sleeping " << endl;
    }


};


class Dog : public Animal
{

    string breed;
    public:
    

    Dog()
    {
        cout <<"default dog constructor called " << endl;

    }

    ~Dog()
    {
        cout << "dog class destroyed" << endl;
    }

    Dog(string name , int age , string breed) : Animal(name,age)
    {
        this->breed=breed;

    }

    void bark()
    {
        cout << name << "is barking " << endl;
    }


};

int main()
{


    Dog d("coco",4,"german shepard");
    Dog d1;
    d.eat();
    d.sleep();
    d.bark();
    
    return 0;
}