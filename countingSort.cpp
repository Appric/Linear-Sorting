#include "linearsort.h"
#include <stack>
#include <vector>

void countSort(struct data arr[], struct data sorted[], int size)
{
    // Find the highest number
    int max = 0;
    for(int loop = 0; loop < size; loop++)
        if(arr[loop].value > 0)
            max = arr[loop].value;

    // Create the count vector
    vector<stack<struct data>> count;

    // Push all count values into the vector
    for(int loop = 0; loop < size; loop++)
    {
        count.at(loop).push(arr[loop]);
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