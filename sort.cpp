#include "linearSort.h"
#include <vector>
#include <queue>
#include <thread>

void sort_functions::countSort(vector<struct data> &arr, vector<struct data> &sorted, int size)
{
    // Find the highest number
    int max = 0;
    for(int loop = 0; loop < size; loop++)
        if(arr[loop].value > max)
            max = arr[loop].value;

    // Create the count queue
    vector<queue<struct data>> count(max + 1);

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

        sorted[loop] = count.at(location).front();
        count.at(location).pop();
    }
}


void sort_functions::heapSort(vector<struct data> &sorted, int size){
    priority_queue<struct data> prioQueue;

    // Push the structs into the priority queue (min heap)
    for(int loop = 0; loop < size; loop++)
        prioQueue.push(sorted[loop]);

    // Pop the structs from the priority queue and store them in sorted
   for(int loop = 0; loop < size; loop++)
   {
        sorted[loop] = prioQueue.top();
        prioQueue.pop();
   }


}

void sort_functions::mergeSort(vector<struct data> &sorted, int size)
{
    if(sorted.size() == 0)
        return;

    // Start the merge
    vector<struct data> temp (size);
    mergeSubset(0, size - 1, sorted, temp, 0);
}

void sort_functions::mergeSubset(int start, int end, vector<struct data> &sub, vector<struct data> &temp, int depth)
{
    // Return at a single item
    if(start == end)
        return;

    // Find the middle
    int mid = (start + end) / 2;

    // Merge the left and right subsets
    if(depth < 3)
    {
        thread one(&sort_functions::mergeSubset, this, start, mid, ref(sub), ref(temp), depth + 1);
        thread two(&sort_functions::mergeSubset, this, mid + 1, end, ref(sub), ref(temp), depth + 1);

        one.join();
        two.join();
    }
    else
    {
        mergeSubset(start, mid, sub, temp, depth + 1);
        mergeSubset(mid + 1, end, sub, temp, depth + 1);
    }

    merge(start, mid, end, sub, temp);
}

void sort_functions::merge(int start, int mid, int end, vector<struct data> &sub, vector<struct data> &temp)
{
    // Keep track of left, right, and sub indexes
    int l = start, r = mid + 1, s = start;

    // Copy current data over to temp
    for(int loop = start; loop <= end; loop++)
        temp[loop] = sub[loop];

    while(l <= mid && r <= end)
    {
        if(temp[l].value < temp[r].value)
            sub[s++] = temp[l++];
        else
            sub[s++] = temp[r++];
    }

    // Fill remaining from the left side
    while(l <= mid)
        sub[s++] = temp[l++];
}