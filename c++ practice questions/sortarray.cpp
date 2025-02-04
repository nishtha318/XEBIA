#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {8,6,3,45,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j =0 ; j < size - i - 1 ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int larger = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = larger;

            }
        }
    }

    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}