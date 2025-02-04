#include <iostream>
using namespace std;

int main()
{
    int m , n ;
    cin >> m >> n;
    int arr[m][n];
    int transpose[n][m];


//for taking input
    for(int r = 0 ; r < m ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> arr[r][c];
        }
    }


//for output
    for(int r = 0 ; r < m ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cout << arr[r][c] << " " ;
        }

        cout << endl;
    }


//for transpose 
for(int r = 0 ; r < n ; r++)
{
    for (int c = 0 ; c < m ; c++)
    {
        transpose[r][c] = arr[c][r];
        
    }

}

//for output of transpose
for(int r = 0 ; r < n ; r++)
{
    for(int c = 0 ; c < m ; c++)
    {
        cout << transpose[r][c] << " " ;
    }

    cout << endl;
}


}