#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "linearSort.h"
#include <string.h>
//113 names
string names[] = {"Jerry", "Jim", "Arnold", "Bob", "Tim", "Ado", "Luke", "Ola", "Will", "Remmy", "Bill", "Josh", "Chad", "Carl", "Caddy", "Madison", "Angela", "Angie", "Anna", "Ana", "Lola", "Laila", "Layla", "Jenna", "Sam", "Logan", "Lane", "Cooper", "Cassie", "Quentin", "Tom", "Keira", "Spencer", "Isaiah", "Gerald", "Geralt", "Radovid", "Hunter", "Triss", "Menge", "Ciri", "Vernon", "Roach", "Epona", "Link", "Zelda", "Gannon", "Mario", "Luigi", "Wario", "Summer", "Ellie", "Scooter", "Steve", "Lilith", "Alex", "Moxxi", "Gary", "Squidward", "Spongebob", "Patrick", "Mr.Krabs", "Sandy", "Pearl", "Plankton", "Barnacle Boy", "Mermaid Man", "Bubble Buddy", "Roland", "Axton", "Salvador", "Zer0", "Maya", "Gaige", "Arambha", "Krieg", "Inigo", "Jack Sparrow", "Davy Jones", "Martin", "Claptrap", "Marcus", "Kratos", "Atreus", "Loki", "Thor", "Zeus", "Hades", "Athena", "Ares", "Helios", "Galatea", "Cronus", "Hyperion", "Rhea", "Theia", "Phoebe", "Apollo","Poseidon", "Hera", "Artemis", "Aphrodite", "Hermes", "Gaia", "Odin", "Cerberus", "Calypso", "Heimdall", "Baldur", "Freya", "Hel", "Freyr", "Bragi"};


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
    srand(113);

    // Print header
    cout << "Data Size - Linear (Counting Sort) - Comparison (Heap Sort) - Parallel Divide and Conquer (Merge Sort)" << endl;

    // Main data creation and timing loop
    for(size; size <= maxSize; size *= 10)
    {
        // Generate the data
        for(int loop = 0; loop < size; loop++)
        {
            if(loop == 0){
                arr[loop].name = "John Hastings";
                arr[loop].value = 10000;
            }
            else{
                arr[loop].name = names[rand() % 113];
                arr[loop].value = rand() % high;
            }
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

     cout << "Top 10 uber drivers and their rating(0-100): " << endl;
    for(int i = 1; i <= 10; i++)
    {
        cout << "Number " << i << " " << sorted[maxSize - i].name << " : " << (float)sorted[maxSize - i].value / 10 << endl;
    }
}