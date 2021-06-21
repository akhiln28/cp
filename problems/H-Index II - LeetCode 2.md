---
Created Time: Feb 04, 2021 8:46 PM
Do Date: Feb 05, 2021
Last edited time: Mar 31, 2021 8:59 AM
Points: 1500
Pomos (25 mins): 1
Relates: H-Index%20-%20LeetCode%2071af86df9a514c50bbca1c20f1721fa2.md
Source: https://leetcode.com/problems/h-index-ii/
Status: done
---

# H-Index II - LeetCode

Given an array of citations **sorted in ascending order** (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index h if h of his/her N papers have **at least** h citations each, and the other N − h papers have **no more than** h citations each."
**Example:**
```
Input: citations = [0,1,3,5,6]Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
```
**Note:**
If there are several possible values for *h*, the maximum one is taken as the h-index.
**Follow up:**
- This is a follow up problem to [H-Index](https://leetcode.com/problems/h-index/description/), where `citations` is now guaranteed to be sorted in ascending order.
- Could you solve it in logarithmic time complexity?
---
```jsx
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0; 
        int left = 0, right = citations.size() - 1; 
        int ans = 0; 
        while (left <= right)
        {
            int mid = (left + right)/2;
            int h = citations.size() - mid; 
            if (citations[mid] >= h)
            {
                ans = max(ans, h); 
                right = mid - 1; 
            }
            else left = mid + 1;  
        }
        return ans; 
    }
};
```
### Lesson Learned:
During binary search inside the array, you need the right to be n - 1, there will be buffer overflow when you use right = n, when there is only single element.
Patterns: [Array](Array.md)[Binary%20Search](Binary%20Search.md)