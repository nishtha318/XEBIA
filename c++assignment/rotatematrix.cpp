#include <iostream>
using namespace std; 
#define MAX 10

void rotate_matrix(int arr[MAX][MAX] , int transpose[MAX][MAX] , int n , int m);



int main()
{
    int n , m;
    cout << "enter the rows of array: " ;
    cin >> n;
    cout << "enter the columns of array: " ;
    cin >> m;

    int arr[MAX][MAX];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j] ;

        }
        
    }

    int transpose[MAX][MAX];

    rotate_matrix(arr , transpose , n , m);
    

    return 0;

}

void rotate_matrix(int arr[MAX][MAX] , int transpose[MAX][MAX] , int n , int m)
{
    //finding transpose of given matrix
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            transpose[r][c] = arr[c][r];
        }
    }

    //reversing each row
    for(int r = 0 ; r < m ; r++)
    {
        for( int c = 0 ; c < n/2 ; c++)
        {
            int first = transpose[r][c];
            int last = transpose[r][n - 1 - c];
            transpose[r][c] = last ; 
            transpose[r][n - 1 - c] = first ;


        }
    }

    cout << "90 degree rotated matrix is: \n" ;
    for(int r = 0 ; r < m ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cout << transpose[r][c] << " ";
        }
        cout << endl;
    }
 
    
}

