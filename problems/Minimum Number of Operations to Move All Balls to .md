---
Created Time: Feb 20, 2021 11:23 PM
Do Date: Feb 22, 2021
Last edited time: Feb 22, 2021 9:52 PM
Points: 1200
Source: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
Status: done
---

# Minimum Number of Operations to Move All Balls to Each Box - LeetCode

You have `n` boxes. You are given a binary string `boxes` of length `n`, where `boxes[i]` is `'0'` if the `ith` box is **empty**, and `'1'` if it contains **one** ball.
In one operation, you can move **one** ball from a box to an adjacent box. Box `i` is adjacent to box `j` if `abs(i - j) == 1`. Note that after doing so, there may be more than one ball in some boxes.
Return an array `answer` of size `n`, where `answer[i]` is the **minimum** number of operations needed to move all the balls to the `ith` box.
Each `answer[i]` is calculated considering the **initial** state of the boxes.
**Example 1:**
```
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
```
**Example 2:**
```
Input: boxes = "001011"
Output: [11,8,5,4,3,4]
```
**Constraints:**
- `n == boxes.length`
- `1 <= n <= 2000`
- `boxes[i]` is either `'0'` or `'1'`.
---
For each index, the minimum number of operations to move all other balls to this location is equal to $ans[i] = leftcount * i - left \space sum + right \space sum - right count * i$
- We can solve that by maintaining cumulative sums and counts.
    ```cpp
    class Solution {
    public:
        vector<int> minOperations(string boxes) {
            int n = boxes.size(); 
            vector<int> locs(n); 
            for (int i = 0; i < n; i++)
            {
                if (boxes[i] == '1')
                {
                    locs[i] = i; 
                }
            }
            vector<int> cum(n), count(n); 
            cum[0] = locs[0];
            for (int i = 1; i < n; i++) cum[i] = cum[i - 1] + locs[i]; 
            for (int i = 0; i < n; i++)
            {
                count[i] = boxes[i] == '1';
                if (i) count[i] += count[i - 1]; 
            }
            // cout << "test" << endl;
            // for (int i = 0; i < n; i++) cout << cum[i] << " "; cout << endl;
            // for (int i = 0; i < n; i++) cout << count[i] << " "; cout << endl;
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
            {
                // cout << "test1" << endl;
                int left_sum = (i ? cum[i - 1] : 0);
                int right_sum = cum[n - 1] - cum[i];
                ans[i] += (i ? count[i - 1] : 0) * i - left_sum + right_sum - (count[n - 1] - count[i]) * i;
            }
            return ans; 
        }
    };
    ```
Below method is new and small. 
```cpp
vector<int> minOperations(string boxes) {
    vector<int> res(boxes.length()); 
    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
       res[i] += ops;
       cnt += boxes[i] == '1' ? 1 : 0;
       ops += cnt;
    }
    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
        res[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    return res;
}
```
Patterns: [Cumulative](Cumulative.md)