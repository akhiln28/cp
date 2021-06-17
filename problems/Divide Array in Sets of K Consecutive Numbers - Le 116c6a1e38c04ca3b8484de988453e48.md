# Divide Array in Sets of K Consecutive Numbers - LeetCode

Created Time: Mar 15, 2021 9:17 AM
Do Date: Mar 16, 2021
Last edited time: Mar 16, 2021 7:32 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
Status: done

Given an array of integers `nums` and a positive integer `k`, find whether it's possible to divide this array into sets of `k` consecutive numbers
 Return `True` if it is possible. Otherwise, return `False`.

**Example 1:**

```
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
```

**Example 2:**

```
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
```

**Example 3:**

```
Input: nums = [3,3,2,2,1,1], k = 3
Output: true
```

**Example 4:**

```
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

**Note:** This question is the same as 846: [https://leetcode.com/problems/hand-of-straights/](https://leetcode.com/problems/hand-of-straights/)

---

The array should be divided into k subarrays of size n/k = d (say). 

Consider the second example, [3,2,1,2,3,4,3,4,5,9,10,11], k = 3 → sort the array → [1, 2, 2, 3, 3, 3, 4, 4, 5, 9, 10, 11].  The smallest three distinct integers in the array should always be in the same group.

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false; 
        
        map<int, int> mp; 
        for (auto e : nums) mp[e]++; 
        vector<pair<int, int>> m_nums; 
        for (auto kv: mp) m_nums.push_back(kv);
        reverse(m_nums.begin(), m_nums.end());
        // pop top k elements until the array is empty
        while (m_nums.size() >= k)
        {
            stack<pair<int, int>> st; 
            int prev = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                auto back = m_nums.back(); m_nums.pop_back();
                if (prev != INT_MIN and back.first != prev + 1) return false; 
                else prev = back.first; 
                if (back.second == 1) continue; 
                st.push({back.first, back.second - 1});
            }
            while (st.size())
            {
                m_nums.push_back(st.top());
                st.pop();
            }
        }
        return m_nums.empty();
    }
};
```