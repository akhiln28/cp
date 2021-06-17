---
Created Time: Dec 04, 2020 2:47 PM
Do Date: Dec 04, 2020
Last edited time: May 11, 2021 9:10 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Knapsack-e1ea6dfd10d74218b7477511a6be96f8
Points: 1500
Problem Statement: You are given a list of integers nums. Consider a tree where nums represents the values of its leaves in an inorder traversal. Internal nodes have have 2 children and their value is equal to the the product of the largest leaf value of its left subtree and the largest leaf value of its right subtree.
Find the tree with the minimum sum of its values and return the sum.
Source: https://binarysearch.com/room/pain.-2M3E1unR1S?questionsetIndex=1
Status: done
---
# Minimum Tree From Leaves
You are given a list of integers `nums`. Consider a tree where `nums` represents the values of its leaves in an inorder traversal. Internal nodes have have `2` children and their value is equal to the the product of the largest leaf value of its left subtree and the largest leaf value of its right subtree.

Find the tree with the minimum sum of its values and return the sum.

For example, given `[2, 3, 5]`, the minimum sum tree is

```
    15
   /  \
  6    5
 / \
2   3 

```

**Constraints**

- `2 ≤ n ≤ 50` where `n` is the length of `nums`
- `1 ≤ nums[i] ≤ 20`

****Example 1****

****Input****

`nums = [2, 3, 5]`

****Output****

`31`

---

```cpp
// returns the 
int solve_recur(vector<int>& nums, int start, int finish, map<pair<int, int>, int>& mp)
{
    if (start == finish) return nums[start];
    
    if (mp.find({start, finish}) != mp.end()) return mp[{start, finish}];
    int ans = INT_MAX; 
    
    for (int i = start + 1; i <= finish; i++)
    {
        int max_left = *max_element(nums.begin() + start, nums.begin() + i); 
        int max_right = *max_element(nums.begin() + i, nums.begin() + finish + 1); 
        int temp = max_left * max_right; 
        temp += solve_recur(nums, start, i - 1, mp) + solve_recur(nums, i, finish, mp);
        ans = min(ans, temp); 
    }
    mp[{start, finish}] = ans; 
    return ans; 
}

int solve(vector<int>& nums) {
    map<pair<int, int>, int> mp; 
    return solve_recur(nums, 0, nums.size() - 1, mp); 
}
```