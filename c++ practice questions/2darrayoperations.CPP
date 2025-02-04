#include<iostream>
using namespace std;

int main()
{
    int m,n;

    cout << "enter the order of a square matrix: " << endl;
    cin >> m >> n;

    int arr[m][n];

    for(int r = 0 ; r < m ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> arr[r][c];
        }

    }

//print the diagnol elements 
cout <<"diagnol elements of array :" << endl;
    for(int r = 0 ; r < m ; r++)
    {
        cout << arr[r][r] << " " ;
    }

    cout << endl;


//print upper triangle elements
cout << "upper trainagular elements" << endl;

    for(int r = 0 ; r < m ; r++)
    { 
        for(int c = 0 ; c < m ; c++)
        {
            if(r<c)
            {
                cout << arr[r][c] << " ";
            }
        }

    }
    cout << endl;
    
//print lower trinagle elements
cout << "lower triangle elements" << endl;

    for(int r = 0 ; r < m ; r++)
    { 
        for(int c = 0 ; c < m ; c++)
        {
            if(r>c)
            {
                cout << arr[r][c] << " " ;
            }
        }

    }
    cout << endl;

//print secondary elements of matrix

cout << "secondary elements of matrix" << endl; 
for(int r = 0 ; r < m ; r++)
{
    for(int c = 0 ; c < n ; c++)
    {
        if ( r + c == m - 1)
        {
            cout << arr[r][c] << " ";
        }
    }
}
 cout << endl;

    




}
