---
Created Time: Dec 22, 2020 11:16 AM
Do Date: Jan 09, 2021
Last edited time: Mar 04, 2021 8:12 AM
Points: 1600
Pomos (25 mins): 1
Related To: Activity%20Selection%20Problem%20b98e4f278b8745d182d05ec2bebc05ef.md
Relates: Delivering%20Boxes%20from%20Storage%20to%20Ports%209dd9d38372434fcfb2d66302b6114425.md
Source: https://leetcode.com/problems/partition-labels/
Status: done
Tags: interval
---

# Partition Labels - Leetcode

A string `S` of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
**Example 1:**
```
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
```
**Note:**
- `S` will have length in range `[1, 500]`.
- `S` will consist of lowercase English letters (`'a'` to `'z'`) only.
---
```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
				// index of the last occurence of each charactor
        vector<int> last(26); 
        for (int i = 0; i < S.length(); i++) 
					last[S[i] - 'a'] = max(last[S[i] - 'a'], i); 
        
        int anchor = 0, end = 0; 
        vector<int> ans; 
        for (int i = 0; i < S.length(); i++)
        {
            end = max(end, last[S[i] - 'a']); 
            if (end == i)
            {
                ans.push_back(i - anchor + 1); 
                anchor = i + 1; 
            }
        }
        return ans; 
    }
};
```
Another approach, 
For each character find the indices of the first and the last occurence in the string. There will be 26 pairs (intervals). We want the maximum number of non intersecting intervals. i.e. activity selection problem.
Patterns: [Two%20Pointers](Two%20Pointers.md)[String](String)[patterns/Greedy](patterns/Greedy.md)[Intervals](Intervals.md)