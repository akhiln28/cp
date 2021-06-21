---
Created Time: Feb 14, 2021 11:35 AM
Do Date: Feb 15, 2021
Last edited time: May 11, 2021 8:58 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/subarray-sums-divisible-by-k/
Status: done
Tags: like
---

# Subarray Sums Divisible by K - Leetcode

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
**Example 1:**
```
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```
**Note:**
1. `1 <= A.length <= 30000`
2. `10000 <= A[i] <= 10000`
3. `2 <= K <= 10000`
---
```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
				// first find the cummulative array
        for (int i = 0; i < A.size(); i++)
        {
            if (i) A[i] += A[i - 1]; 
            A[i] %= K;
            A[i] = (A[i] + K) % K; 
        }
        unordered_map<int, int> mp; 
        int ans = 0; 
        mp[0] = 1; 
        // for (int i = 0; i < A.size(); i++) cout << A[i] << " "; cout << endl;
        for (int i = 0; i < A.size(); i++)
        {
            if (mp.find(A[i]) == mp.end())
            {
                mp[A[i]]++; 
            }
            else
            {
                ans += mp[A[i]]; 
                mp[A[i]]++; 
            }
        }
        return ans; 
    }
};
```
Patterns: [Matrix](Matrix.md)[Hashing](Hashing.md)