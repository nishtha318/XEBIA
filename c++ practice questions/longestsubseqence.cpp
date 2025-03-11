#include <iostream>
using namespace std;

int main()
{
    int arr[7] = { 1 , 9 , 3 , 7 , 8 , 10 , 20} ;
    int size = sizeof(arr) / sizeof(arr[0]);


    //sort the array (bubble sort)
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if(arr [j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
            }

        }
    }

    int counter = 1 , max = 1 , startindex = 0 , reset = 0 ; 
    for(int i = 0 ; i < size - 1 ; i ++)
    {
        if(arr[i] == arr[i-1] + 1)
        {
            counter ++;
        }

        else if (arr[i] != arr[i-1])
        {
            if (counter > max)
            {
                max = counter ;
                reset = startindex ;

            }
            counter = 1 ;
            startindex = i ; //breaking subsequence 
        }
        
    }

    if (counter > max)
    {
        max = counter;
        reset = startindex;
    }


    cout << "Longest consecutive subsequence: ";
    for (int i = reset ; i < reset + max; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;


}