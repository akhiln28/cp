# Maximum Subarray Sum with One Deletion - Leetcode

Created Time: Jan 24, 2021 8:10 AM
Do Date: Mar 08, 2021
Last edited time: Mar 15, 2021 8:06 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Subarray-ef1d425ad64945bf849cd2e45d4ee4aa, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
Status: done
Tags: goldman sachs, subarray

Given an array of integers, return the maximum sum for a **non-empty** subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be **non-empty** after deleting one element.

**Example 1:**

```
Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
```

**Example 2:**

```
Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
```

**Example 3:**

```
Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `10^4 <= arr[i] <= 10^4`

---

- Initial approach

    ```cpp
    class Solution {
    public:
        int maximumSum(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0]; 
            vector<int> suffix_sum(n), prefix_sum(n); 
            
            suffix_sum[n - 1] = arr[n - 1]; 
            prefix_sum[0] = arr[0];
            // finding prefix and suffix sums
            for (int i = 1; i < n; i++) prefix_sum[i] = arr[i] + prefix_sum[i - 1]; 
            for (int i = n - 2; i >= 0; i--) suffix_sum[i] = arr[i] + suffix_sum[i + 1]; 
            
            vector<int> suffix_prefix_max(n), prefix_suffix_max(n); 
            suffix_prefix_max[0] = suffix_sum[0], prefix_suffix_max[n - 1] = prefix_sum[n - 1]; 
            
            for (int i = 1; i < n; i++) suffix_prefix_max[i] = max(suffix_sum[i], suffix_prefix_max[i - 1]); 
            for (int i = n - 2; i >= 0; i--) prefix_suffix_max[i] = max(prefix_sum[i], prefix_suffix_max[i + 1]); 
            
            long long ans = INT_MIN; 
            for (int i = 0; i < n; i++)
            {
                long long left_sum = INT_MIN; 
                if (i) left_sum = suffix_prefix_max[i - 1] - suffix_sum[i];
                long long right_sum = INT_MIN; 
                if (i + 1 < n) right_sum = prefix_suffix_max[i + 1] - prefix_sum[i];
                long long remOne = max({left_sum + right_sum, left_sum, right_sum});
                remOne = max(remOne, remOne + arr[i]);
                ans = max(ans, remOne);
            }
            return ans; 
        }
    };
    ```

An efficient approach from 

[Error - LeetCode Discuss](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/377397/Intuitive-Java-Solution-With-Explanation)

**Idea**

Compute `maxEndHere` and `maxStartHere` arrays and also find overall `max` along with them.Now, evaluate the case where 1-element can be eliminated, that is at each index, we can make use of `maxEndHere[i-1]+maxStartHere[i+1]`

**Thought process**

This approach is a slight improvisation on the idea of [https://leetcode.com/problems/maximum-subarray/](https://leetcode.com/problems/maximum-subarray/). Basically, the difference here is we can eliminate 1 number and still can continue with expanding our subarray. So imagine a subarray where you removed 1 element, then it forms two subarrays ending at prev index and starting at next index. We know how to get `maxEndHere` from the max sum subarray problem for each index. If we reverse our thinking to follow the same logic to solve for subarray at next index, we should be able to see computing `maxStartHere` is just backwards of `maxEndHere`. So now at each index, it is just about looking at prev and next numbers from the respective arrays to get overall `max`.

```java
public int maximumSum(int[] a) {
    int n = a.length;
    int[] maxEndHere = new int[n], maxStartHere = new int[n];
    int max = a[0];
    maxEndHere[0] = a[0];
    for(int i=1; i < n; i++){
        maxEndHere[i] = Math.max(a[i], maxEndHere[i-1]+a[i]);
        max = Math.max(max, maxEndHere[i]);
    }
    maxStartHere[n-1] = a[n-1];
    for(int i=n-2; i >= 0; i--)
        maxStartHere[i] = Math.max(a[i], maxStartHere[i+1]+a[i]);
    for(int i=1; i < n-1; i++)
        max = Math.max(max, maxEndHere[i-1]+maxStartHere[i+1]);
    return max;
}
```

- My approach

    ```cpp
    class Solution {
    public:
        int maximumSum(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0]; 
            vector<int> suffix_sum(n), prefix_sum(n); 
            
            suffix_sum[n - 1] = arr[n - 1]; 
            prefix_sum[0] = arr[0];
            // finding prefix and suffix sums
            for (int i = 1; i < n; i++) prefix_sum[i] = arr[i] + prefix_sum[i - 1]; 
            for (int i = n - 2; i >= 0; i--) suffix_sum[i] = arr[i] + suffix_sum[i + 1]; 
            
            vector<int> suffix_prefix_max(n), prefix_suffix_max(n); 
            suffix_prefix_max[0] = suffix_sum[0], prefix_suffix_max[n - 1] = prefix_sum[n - 1]; 
            
            for (int i = 1; i < n; i++) suffix_prefix_max[i] = max(suffix_sum[i], suffix_prefix_max[i - 1]); 
            for (int i = n - 2; i >= 0; i--) prefix_suffix_max[i] = max(prefix_sum[i], prefix_suffix_max[i + 1]); 
            
            long long ans = INT_MIN; 
            for (int i = 0; i < n; i++)
            {
                long long left_sum = INT_MIN; 
                if (i) left_sum = suffix_prefix_max[i - 1] - suffix_sum[i];
                long long right_sum = INT_MIN; 
                if (i + 1 < n) right_sum = prefix_suffix_max[i + 1] - prefix_sum[i];
                long long remOne = max({left_sum + right_sum, left_sum, right_sum});
                remOne = max(remOne, remOne + arr[i]);
                ans = max(ans, remOne);
            }
            return ans; 
        }
    };
    ```