---
Created Time: Feb 14, 2021 10:54 AM
Do Date: Feb 14, 2021
Last edited time: May 11, 2021 8:58 AM
Points: 1600
Source: https://leetcode.com/problems/sum-of-subarray-minimums/
Status: ok
Tags: like
---

# Sum of Subarray Minimums - Leetcode

Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `109 + 7`.
**Example 1:**
```
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17
```
**Example 2:**
```
Input: arr = [11,81,94,43,3]
Output: 444
```
**Constraints:**
- `1 <= arr.length <= 3 * 104`
- `1 <= arr[i] <= 3 * 104`
---
```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7; 
        // for each element the number of times that particular element acts as the minimum of the subarray. 
        // for each element find first element less than or equal to the current element to both left and right
        // ans is sum of (for each element (width)c2);
        int n = arr.size(); 
        vector<long long> left(n, -1), right(n, n); 
        stack<int> st; 
        // finding the left of each element
        for (int i = 0; i < n; i++)
        {
            if (st.empty()) st.push(i); 
            // not strictly less
            else if (arr[i] >= arr[st.top()])
            {
                left[i] = st.top(); 
                st.push(i); 
            }
            else
            {
                while(st.size() and arr[i] < arr[st.top()])
                {
                    st.pop(); 
                }
                if (st.size())
                {
                    left[i] = st.top(); 
                }
                st.push(i); 
            }
        }
        while(st.size()) st.pop(); 
        // finding the right of each element
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty()) st.push(i);
            // strictly less
            else if (arr[i] > arr[st.top()])
            {
                right[i] = st.top(); 
                st.push(i); 
            }
            else
            {
                while (st.size() and arr[i] <= arr[st.top()])
                {
                    st.pop(); 
                }
                if (st.size())
                {
                    right[i] = st.top(); 
                }
                st.push(i); 
            }
        }
        // for (int i = 0; i < n; i++) cout << left[i] << " "; cout << endl;
        // for (int i = 0; i < n; i++) cout << right[i] << " "; cout << endl;
        long long ans = 0; 
        for (int i = 0; i < n; i++)
        {
            ans = (ans + arr[i] * (i - left[i]) * (right[i] - i)) % mod; 
        }
        return ans; 
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Number%20Theory](Number%20Theory.md)[Stack](Stack.md)