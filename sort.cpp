#include "linearSort.h"
#include <stack>
#include <vector>
#include <queue>

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
        while(count.at(location).empty() && location < max)
                location++;

        sorted[loop] = count.at(location).top();
        count.at(location).pop();
    }
}


void sort_functions::heapSort(vector<struct data> &sorted, int size){
<<<<<<< HEAD
=======
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
>>>>>>> 4836a698d5614e2ccca0f4ff0a92052079c4c19b

}
