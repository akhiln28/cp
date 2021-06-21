---
created at: 2021-06-17
author: akhiln
tags: [problem]
---

# minimize maximum pair sum in array

### Problem Statement
The maximum pair sum is the largest pair sum in a list of pairs. Given a list of n integers `nums`, pair up the elements into $n/2$ pairs such that:
- each element in `nums` is in exactly on pair, and
- the maximum pair sum is minimized

#### Examples
Input: [3, 5, 2, 3]
	[2 3 3 5]
	[2 + 5, 3 + 3]
output: 7

### Solution
- Sort the array
- Use two pointer approach for creating pairs. One at the start and other at the end.

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n/2; i++) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        return ans;
    }
};
```
The solution seems very simple but how to go about by the correctness of the solution?

#### Related
- [[Optimization]]
- [Optimization Function](Optimization%20Function.md)