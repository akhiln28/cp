---
Created Time: Feb 08, 2021 8:42 AM
Do Date: Feb 12, 2021
Last edited time: Feb 26, 2021 8:30 AM
Points: 1600
Pomos (25 mins): 1
Source: https://www.geeksforgeeks.org/quick-sort/
Status: done
---

# QuickSort - GeeksforGeeks

Like [Merge Sort](http://quiz.geeksforgeeks.org/merge-sort/), Quicksort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quicksort that pick pivot in different ways.
1. Always pick first element as pivot.
2. Always pick last element as pivot (implemented below)
3. Pick a random element as pivot.
4. Pick median as pivot.
```cpp
void quickSort(int arr[], int low, int high)
{
    // code here
    if (low >= high) return; 
    
    int ptr = partition(arr, low, high); 
    quickSort(arr, low, ptr - 1); 
    quickSort(arr, ptr + 1, high); 
}
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot = arr[high]; 
   int i = low;
   for (int j = low; j <= high; j++)
   {
       if (arr[j] < pivot)
       {
           swap(arr[i], arr[j]); 
           i++; 
       }
   }
   swap(arr[i], arr[high]); 
   return i; 
}
```
Patterns: [Array](Array.md)[Partition](Partition.md)