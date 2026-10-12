#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "linearSort.h"

// Create the data and sort using counting sort
int main()
{
    // Sort Functions instance
    sort_functions sort;

    // Variables
    int size = 10;
    int const maxSize = 10000000;
    //int const maxSize = 1000;
    int high = 10000;
    vector<struct data> arr(maxSize);
    vector<struct data> sorted(maxSize);

    // Seed the randomizer
    srand(10);

    // Print header
    cout << "Data Size - Linear (Counting Sort) - Comparison (Heap Sort) - Parallel Divide and Conquer (Merge Sort)" << endl;

    // Main data creation and timing loop
    for(size; size <= maxSize; size *= 10)
    {
        // Generate the data
        for(int loop = 0; loop < size; loop++)
        {
            arr[loop].name = "Data " + to_string(loop);
            arr[loop].value = rand() % high;
        }

        // Print data size
        cout << setw(9) << size;

        // Time and call countSort
        auto start = chrono::steady_clock::now();
        sort.countSort(arr, sorted, size);
        auto end = chrono::steady_clock::now();

        // Print the time
        cout << setw(22) << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms";

        // Time and call heapSort
        sorted = arr;
        start = chrono::steady_clock::now();
        sort.heapSort(sorted, size);
        end = chrono::steady_clock::now();

        // Print the time
        cout << setw(22) << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms";

        // Time and call mergeSort
        sorted = arr;
        start = chrono::steady_clock::now();
        sort.mergeSort(sorted, size);
        end = chrono::steady_clock::now();

        // Print the time
        cout << setw(40) << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms";

        // Print new line
        cout << endl;
    }
}