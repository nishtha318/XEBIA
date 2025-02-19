#include <iostream>
using namespace std;

void draw(int h);

int main()
{
    int h;
    cout << "enter the height of the pyramid" ;
    cin >> h;

    draw(h);
}

void draw(int h)
{
    if(h <= 0)
    {
        return;
    }

    

    for(int i = 0 ; i < h ; i++)
    {
        cout << "#";
    }

    cout << endl;

    draw(h - 1);
}
