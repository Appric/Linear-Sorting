#include "linearSort.h"
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

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


void sort_functions::heapSort(vector<struct data> &sorted, int size){
    make_heap(sorted.begin(), sorted.end(), greater<struct data>());
    //greater parameter flips the comparison sign
    for(auto i = sorted.end(); i != sorted.begin(); i--)
    { //put stucts into the heap or priority queue
        pop_heap(sorted.begin(), i, greater<struct data>());
    }

   reverse(sorted.begin(), sorted.end());

}
