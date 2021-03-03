#include <iostream> 
#include <vector>
using namespace std; 

class segment_tree
{
    public: 
    segment_tree(int n)
    {
        int size = 1; 
        while (size < n) sizes <<= 1; 
        arr.resize(n); 
    }
    
    private:
    vector<int> arr;
}