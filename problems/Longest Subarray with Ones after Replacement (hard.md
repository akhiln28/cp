---
Created Time: Feb 10, 2021 8:22 AM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:00 AM
Points: 1600
Related To: Longest%20Substring%20with%20Same%20Letters%20after%20Replacem%200094a2a5bc664ac98da0d5d185b52937.md
Source: https://www.educative.io/courses/grokking-the-coding-interview/B6VypRxPolJ
Status: done
---

# Longest Subarray with Ones after Replacement (hard)

Given an array containing 0s and 1s, if you are allowed to **replace no more than ‘k’ 0s with 1s**, find the length of the **longest contiguous subarray having all 1s**.
**Example 1:**
```
Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
```
**Example 2:**
```
Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.
```
---
my code
```jsx
using namespace std;
#include <iostream>
#include <vector>
class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0, n = arr.size();
    // TODO: Write your code here
    int end = 0, ones = (arr[0] == 1);
    for (int start = 0; start < n; start++)
    {
        while (end + 1 < n and end + 1 - start + 1 - (ones + (arr[end + 1] == 1)) <= k)
        {
            end++; 
            ones = ones + (arr[end] == 1);
        }
        maxLength = max(maxLength, end - start + 1); 
        if (arr[start] == 1) ones--;
    }
    return maxLength;
  }
};
```
[educative.io](http://educative.io) code
```jsx
using namespace std;
#include <iostream>
#include <vector>
class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int windowStart = 0, maxLength = 0, maxOnesCount = 0;
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      if (arr[windowEnd] == 1) {
        maxOnesCount++;
      }
      // current window size is from windowStart to windowEnd, overall we have a maximum of 1s
      // repeating a maximum of 'maxOnesCount' times, this means that we can have a window with
      // 'maxOnesCount' 1s and the remaining are 0s which should replace with 1s.
      // now, if the remaining 0s are more than 'k', it is the time to shrink the window as we
      // are not allowed to replace more than 'k' Os
      if (windowEnd - windowStart + 1 - maxOnesCount > k) {
        if (arr[windowStart] == 1) {
          maxOnesCount--;
        }
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};
int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)