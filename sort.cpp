#include "linearSort.h"
#include <stack>
#include <vector>
#include <queue>
#include <functional> //used to invert standard heap into min heap

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
    priority_queue<int , vector<struct data>, greater<int>> min_heap; 
    //greater parameter flips the comparison sign
    for(int i = 0; i < size; i++)
    { //put stucts into the heap or priority queue
        min_heap.push(sorted[i]);
    }

    int k = 0;
    while(!min_heap.empty())
    {
        sorted[k] = min_heap.top();
        min_heap.pop();
        k++;
    }
    return;


}