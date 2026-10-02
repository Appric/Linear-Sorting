#include <iostream>
#include "linearSort.h"

// Create the data and sort using counting sort
int main()
{
    // Sort Functions instance
    sort_functions sort;

    // Test Data
    int const size = 20;
    struct data arr[size];
    struct data sorted[size];
    srand(10);
    for(int loop = 0; loop < size; loop++)
    {
        arr[loop].name = "Test " + loop;
        arr[loop].value = rand() % 100;
    }

    // Test Print
    cout << "Unsorted Data:" << endl;
    for(int loop = 0; loop < size; loop++)
    {
        cout << arr[loop].value << " ";
    }
    cout << endl;

    // Test countSort
    sort.countSort(arr, sorted, size);

        // Test Print
    cout << "Sorted Data:" << endl;
    for(int loop = 0; loop < size; loop++)
    {
        cout << sorted[loop].value << " ";
    }
    cout << endl;
}