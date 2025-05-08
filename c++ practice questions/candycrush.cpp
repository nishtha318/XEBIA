#include <iostream>
using namespace std;

class Candy
{
    string color;
    int points;

    public:
    Candy()
    {
        color= "unknown";
        points = 0;
    }

    Candy(string c , int p)
    {
        color = c;
        points = p;
    }

    Candy(const Candy &c)
    {
         color = c.color;
         points = c.points;
    }
    void setCandy(string c , int p);
    void displayCandy();

};

void Candy :: setCandy(string c, int p)
{
    color = c;
    points = p;
}

void Candy :: displayCandy()
{
    cout << color << "is the color" << endl;
    cout << points << "are the points" << endl;
}


int main()
{
    Candy c1("Red", 100); 
    c1.displayCandy();

    Candy c2("Green", 8); 
    c2.displayCandy();

    Candy c3 = c1; 
    c3.displayCandy();

}