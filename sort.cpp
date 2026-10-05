#include "linearSort.h"
#include <stack>
#include <vector>

void sort_functions::countSort(vector<struct data> &arr, vector<struct data> &sorted, int size)
{
    // Find the highest number
    int max = 0;
    for(int loop = 0; loop < size; loop++)
        if(arr[loop].value > max)
            max = arr[loop].value;

    // Create the count vector
    vector<stack<struct data>> count(max + 1);

    // Push all count values into the vector
    for(int loop = 0; loop < size; loop++)
    {
        count.at(arr[loop].value).push(arr[loop]);
    }

    // Fill the sorted array with the data
    int location = 0;
    for(int loop = 0; loop < size; loop++)
    {
        while(count.at(location).empty())
                location++;

        sorted[loop] = count.at(location).top();
        count.at(location).pop();
    }
}

void sort_functions::heapSort(){
    
}