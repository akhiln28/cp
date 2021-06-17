# Top K Frequent Elements - Leetcode

Created Time: Feb 26, 2021 8:46 AM
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1600
Pomos (25 mins): 2
Related To: Top%20k%20largest%20elements%20773ec208a41d401287f6ba91cb8f4c5b.md
Source: https://leetcode.com/problems/top-k-frequent-elements/
Status: ok

Given a non-empty array of integers, return the **k** most frequent elements.

**Example 1:**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

---

The straight forward method I could think of is by hashing frequencies for all the elements and then sorting the elements based on their frequencies.