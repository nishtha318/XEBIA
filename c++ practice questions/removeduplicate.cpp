#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10,23,10,87,99,23};

    int temp;

    int size = sizeof(arr) / sizeof(arr[0]) ;

    for(int i=0 ; i < size - 1 ; i++)
    {
        for (int j = i+1 ; j < size ;)
        {
            
            if (arr[i] == arr[j])
            {
                for(int k = j ; k < size - 1 ; k++)
                 {
                    arr[k] = arr[k+1];

                 }
                 size--;
            }
            else
            {
                j++;
            }

        }
    }

    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << "  ";
    }
}