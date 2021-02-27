#include <iostream>
#include <vector>

using namespace std; 

// will partition the array with arr[end] as a the pivot and returns the final position of the pivot
int partition(vector<int>& arr, int start, int end)
{
    int pivot = arr[end]; 
    int j = start, i = start; 
    for (i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[j++], arr[i]); 
        }
    }
    swap(arr[j], arr[end]); 
    return j;
}

void quick_sort(vector<int>& arr, int start, int end)
{
    if (start >= end) return; 
    int mid = partition(arr, start, end); 
    quick_sort(arr, start, end - 1); 
    quick_sort(arr, mid + 1, end); 
}

int main()
{
    vector<int> arr{1,3, 7, 19, 27, 1, 29, 8, 11}; 
    quick_sort(arr, 0, arr.size() - 1); 
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
    return 0; 
}