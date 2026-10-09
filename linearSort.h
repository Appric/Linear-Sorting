#include <string>
#include <vector>

using namespace std;

struct data
{
    string name;
    int value;

    bool operator>(const data& other) const{
        return value < other.value;
    }
};

class sort_functions
{
    public:
        void countSort(vector<struct data> &arr, vector<struct data> &sorted, int size);
        void heapSort(vector<struct data> &sorted, int size);
};