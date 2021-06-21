---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 24, 2021
Last edited time: Mar 01, 2021 3:42 PM
Points: 1500
Relates: Previous%20Permutation%209ab94d40129b46819e68ee80d41e42b4.md
Status: done
---

# Next Permutation

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be **[in place](http://en.wikipedia.org/wiki/In-place_algorithm)** and use only constant extra memory.
**Example 1:**
```
Input: nums = [1,2,3]
Output: [1,3,2]
```
**Example 2:**
```
Input: nums = [3,2,1]
Output: [1,2,3]
```
**Example 3:**
```
Input: nums = [1,1,5]
Output: [1,5,1]
```
**Example 4:**
```
Input: nums = [1]
Output: [1]
```
**Constraints:**
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`
---
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                reverse(nums.begin() + i + 1, nums.end());
                auto it = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
                int temp = *it;
                *it = nums[i];
                nums[i] = temp;
                flag = true;
                break;
            }
        }
        if (!flag) reverse(nums.begin(), nums.end());
    }
};
```
Patterns: [Array](Array.md)[Sorting%20Algorithms](Sorting%20Algorithms.md)[patterns/Greedy](patterns/Greedy.md)