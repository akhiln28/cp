# Trapping Rain Water

Created Time: Dec 01, 2020 11:51 PM
Last edited time: Feb 22, 2021 9:25 PM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242
Points: 2000
Pomos (25 mins): 2
Relates: Maximum%20Score%20of%20a%20Good%20Subarray%20-%20Leetcode%203a578c487dea4a9da19e607ccbce6b7c.md
Status: done

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

![https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

- `n == height.length`
- `0 <= n <= 3 * 10^4`
- `0 <= height[i] <= 10^5`

---

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size()) return 0;
				// prefix and suffix maximums
        vector<int> max_left(height.size()), max_right(height.size());
        
        max_left[0] = height[0];
        for (int i = 1; i < max_left.size(); i++)
            max_left[i] = max(max_left[i - 1], height[i]);
        
        max_right[max_right.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--)
            max_right[i] = max(max_right[i + 1], height[i]);
        
        vector<int> updated_heights(height.size());
        updated_heights[0] = height[0], updated_heights[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < height.size() - 1; i++)
        {
            updated_heights[i] = max(height[i], min(max_left[i - 1], max_right[i + 1]));
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
            ans += updated_heights[i] - height[i];
        return ans;
    }
};
```