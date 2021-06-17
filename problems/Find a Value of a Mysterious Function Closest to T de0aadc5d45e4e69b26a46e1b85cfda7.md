# Find a Value of a Mysterious Function Closest to Target - LeetCode

Created Time: Jan 15, 2021 3:50 PM
Do Date: Jan 15, 2021
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Points: 2000
Pomos (25 mins): 1
Source: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
Status: done
Tags: new

![Find%20a%20Value%20of%20a%20Mysterious%20Function%20Closest%20to%20T%20de0aadc5d45e4e69b26a46e1b85cfda7/change.png](change.png)

Winston was given the above mysterious function `func`. He has an integer array `arr` and an integer `target` and he wants to find the values `l` and `r` that make the value `|func(arr, l, r) - target|` minimum possible.

Return *the minimum possible value* of `|func(arr, l, r) - target|`.

Notice that `func` should be called with the values `l` and `r` where `0 <= l, r < arr.length`.

**Example 1:**

```
Input: arr = [9,12,3,7,15], target = 5
Output: 2
Explanation: Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.
```

**Example 2:**

```
Input: arr = [1000000,1000000,1000000], target = 1
Output: 999999
Explanation: Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.
```

**Example 3:**

```
Input: arr = [1,2,4,8,16], target = 0
Output: 0
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^6`
- `0 <= target <= 10^7`

---

I found the method in the leetcode discuss very useful. Apparently the below method can be used for finding the total number of OR's and GCD's for all subarrays. (meaning the approach would be the same even if the AND is replaced by OR or GCD)

```cpp
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX;
				// s[i] - is the set of all and values of subarrays starting at i
        set<int> s[n]; 
        s[n - 1].insert(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            s[i].insert(arr[i]); 
            for (auto e : s[i + 1])
            {
                s[i].insert(e & arr[i]); 
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto e : s[i])
            {
                ans = min(ans, abs(e - target));
            }
        }
        return ans; 
    }
};
```