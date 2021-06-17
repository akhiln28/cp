# Kth Largest Element in an Array - LeetCode

Created Time: Feb 12, 2021 7:37 AM
Do Date: Feb 26, 2021
Last edited time: Feb 26, 2021 8:45 AM
Pattern: https://www.notion.so/Partition-bca5c9012e0e421198bcc258e96c6797
Points: 1700
Pomos (25 mins): 2
Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
Status: done

Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

**Example 2:**

```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```

**Note:** 
 You may assume k is always valid, 1 ≤ k ≤ array's length.

---

The complexity can be reduced by choosing a random pivot. 

```cpp
class Solution {
public:
    int partition(vector<int>& nums, int start, int end)
    {
        int pivot = nums[end]; 
        int i = start, j = start; 
        for (j = start; j < end; j++)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[i++], nums[j]); 
            }
        }
        swap(nums[i], nums[end]); 
        return i; 
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(); 
        int start = 0, end = n - 1; 
        
        while (start <= end)
        {
            int idx = partition(nums, start, end); 
            if (idx == n - k) return nums[idx];
            if (idx < n - k) start = idx + 1; 
            else end = idx - 1; 
        }
        return 0;
    }
};
```