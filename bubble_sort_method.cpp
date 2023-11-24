#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n)
{
    bool swapped;

    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        //if two elements haven't swapped
        if(!swapped)
        {
            break;
        }
    }
}

//print the array
void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    int N = 7;
    int numbers[N] = {64, 34, 25, 12, 21, 98, 11};

    //use this when you don't know the size of the array
    //int N = sizeof(numbers) / sizeof(numbers[0]); // the end of the array and the start of the array

    cout << "Before sorting: " << endl;
    for(int i = 0; i < N; i++)
    {
        cout << " " << numbers[i];
    }

    bubble_sort(numbers, N);

    cout << endl;
    cout << "After sorting: " << endl;
    print_arr(numbers, N);

    return 0;
}
