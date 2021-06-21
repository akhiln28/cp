---
Created Time: Dec 21, 2020 7:46 PM
Do Date: Dec 21, 2020
Last edited time: Mar 01, 2021 8:38 AM
Status: done
---

# Squaring a Sorted Array

### **Problem Statement [#](https://www.educative.io/courses/grokking-the-coding-interview/R1ppNG3nV9R#problem-statement)**
Given a sorted array, create a new array containing **squares of all the numbers of the input array** in the sorted order.
**Example 1:**
```
Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
```
**Example 2:**
```
Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]
```
---
```cpp
using namespace std;
#include <iostream>
#include <vector>
class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int start = 0, end = n - 1, ptr = n - 1; 
    while (start <= end)
    {
        if (abs(arr[start]) > abs(arr[end])) squares[ptr] = arr[start] * arr[start], start++, ptr--;
        else squares[ptr] = arr[end] * arr[end], end--, ptr--; 
    }
    return squares;
  }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)