#include <iostream>

using namespace std; 

struct min_heap
{
    int *harr; 
    int capacity, size = 0; 

    min_heap(int capacity) : capacity(capacity), size(0)
    {
        harr = new int[capacity];
    }

    void min_heapify(int i)
    {
        
    }

    int get_min()
    {
        return harr[0]; 
    }

    int extract_min()
    {

    }
};