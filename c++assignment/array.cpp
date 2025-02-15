#include <iostream>
using namespace std;

void reverse_arr(int arr[] , int n);
void find_max(int arr[] , int n);
void find_min(int arr[] , int n);

int main()
{
    int n ;
    cout << "enter number of elements in array\n";
    cin >> n;

    //array of size n 
    int arr[n];

    cout << "enter" << " " << n << " " << "elements of the array\n";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    reverse_arr(arr , n);
    find_max(arr , n);
    find_min(arr , n);
     
}

void reverse_arr(int arr[] , int n)
{
    for(int i = 0 ; i < n / 2 ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;

    }
    
    cout << "reversed array is :" << " " ;
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void find_max(int arr[] , int n)
{
    int largest , second_largest ;

    if(arr[0] > arr[1])
    {
         largest = arr[0];
         second_largest = arr[1];
    }
    else 
    {
        second_largest = arr[0];
        largest = arr[1];
    }

    for(int i = 2 ; i < n ; i++)
    {
        if(arr[i] > largest)
        {
            second_largest = largest ;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
        
    }
    cout << "second largest element in the array is :" <<" " << second_largest << endl ;
   

}

void find_min(int arr[] , int n)
{
    int minimum , second_minimum ;

    if(arr[0] < arr[1])
    {
         minimum = arr[0];
         second_minimum = arr[1];
    }
    else
    {
        second_minimum = arr[0];
        minimum = arr[1]; 
    }

    for(int i = 2 ; i < n ; i++)
    {
        if(arr[i] < minimum)
        {
            second_minimum = minimum;
            minimum = arr[i];
        }
        else if (arr[i] < second_minimum && arr[i] != minimum)
        {
            second_minimum = arr[i];
        }
        
    }
    cout << "second minimum element in the array is :" << " " << second_minimum ;
   
}






