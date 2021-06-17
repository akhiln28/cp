# Largest Submatrix With Rearrangements - LeetCode

Created Time: Jan 16, 2021 9:34 AM
Do Date: Jan 10, 2021
Last edited time: Mar 01, 2021 8:47 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1700
Pomos (25 mins): 3
Relates: Largest%20One%20Submatrix%20with%20Column%20Swaps%20binarysear%205e7965432f094672bf82ec385ade3689.md
Source: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
Status: done
Tags: new

You are given a binary matrix `matrix` of size `m x n`, and you are allowed to rearrange the **columns** of the `matrix` in any order.

Return *the area of the largest submatrix within* `matrix` *where **every** element of the submatrix is* `1` *after reordering the columns optimally.*

**Example 1:**

![Largest%20Submatrix%20With%20Rearrangements%20-%20LeetCode%20533a14be49a74598be0877ba4a886fbb/screenshot-2020-12-30-at-40536-pm.png](screenshot-2020-12-30-at-40536-pm.png)

```
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
```

**Example 2:**

```
Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
```

**Example 3:**

```
Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
```

**Example 4:**

```
Input: matrix = [[0,0],[0,0]]
Output: 0
Explanation: As there are no 1s, no submatrix of 1s can be formed and the area is 0.
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m * n <= 105`
- `matrix[i][j]` is `0` or `1`.

---

[C++ Solution | Easy Implementation - LeetCode Discuss](https://leetcode.com/problems/largest-submatrix-with-rearrangements/discuss/1020576/C%2B%2B-Solution-or-Easy-Implementation)

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(); 
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
								// store the cummulative sum incase of continuous streak
                if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];
            }
        }
        int ans = 0; 
        for (int i = 0; i < n; i++)
        {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            int mine = matrix[i][0];
            ans = max(ans, mine);
            for (int j = 1; j < m; j++)
            {
                mine = min(mine, matrix[i][j]); 
                ans = max(ans, mine * (j + 1));
            }
        }
        return ans;
    }
};
```