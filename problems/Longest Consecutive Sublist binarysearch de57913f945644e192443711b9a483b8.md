# Longest Consecutive Sublist | binarysearch

Created Time: Feb 18, 2021 1:24 PM
Do Date: Feb 19, 2021
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1700
Source: https://binarysearch.com/problems/Longest-Consecutive-Sublist
Status: done

You are given a list of unique integers `nums`. Return the length of the longest sublist containing consecutive elements.

### **Example 1**

****Input****

`nums = [1, 4, 5, 3, 2, 9]`

****Output****

`5`

### **Explanation**

The sublist `[1, 4, 5, 3, 2]` contains consecutive elements from `1` to `5`.

### **Example 2**

****Input****

`nums = [2, 4, 6, 8, 3, 5, 7]`

****Output****

`7`

### **Explanation**

The whole list contains consecutive elements from `2` to `8`.

### **Example 3**

****Input****

`nums = []`

****Output****

`0`

### **Constraints**

- `0 ≤ n ≤ 1,000` where `n` is the length of `nums`

---

An interval $(i, j)$ has consecutive numbers if $j - i + 1 == max({i...j}) - min({i..j}) + 1$. Since all the numbers are unique. 

```cpp
int solve(vector<int>& nums) {
    if (nums.size() == 0) return 0; 
    int ans = 1; 
    for (int i = 0; i < nums.size(); i++)
    {
        int mine = nums[i], maxe = nums[i]; 
        for (int j = i + 1; j < nums.size(); j++)
        {
            mine = min(nums[j], mine); 
            maxe = max(nums[j], maxe); 
            if (j - i + 1 == maxe - mine + 1)
            {
                ans = max(ans, j - i + 1); 
            }
        }
    }
    return ans; 
}
```

### Learned:

We can iterate over all subarrays while finding minimum and maximum in each subarray in O(n^2).