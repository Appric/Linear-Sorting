#include <string>

using namespace std;

struct data
{
    string name;
    int value;
};

class sort_functions
{
    public:
        void countSort(struct data arr[], struct data sorted[], int size);
        void heapSort(struct data sorted[], int size);
};