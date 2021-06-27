---
Created Time: Feb 16, 2021 3:16 PM
Last edited time: May 23, 2021 8:53 AM
Points: 1700
Pomos (25 mins): 1
Source: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
Status: waiting
---

# Longest [Substring](Substring.md) with At Least K Repeating Characters - Leetcode

Given a string `s` and an integer `k`, return *the length of the longest substring of* `s` *such that the frequency of each character in this substring is greater than or equal to* `k`.
**Example 1:**
```
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
```
**Example 2:**
```
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```
**Constraints:**
- `1 <= s.length <= 10^4`
- `s` consists of only lowercase English letters.
- `1 <= k <= 10^5`
---
To apply the standard sliding window protocol, I don't think there is monotonicity. For example consider for k = 2
$$abbccca$$
for start = 0, end = 6, but for start = 1, end = 5 which is less than 6. so, there is no monotonicity. We cannot apply the standard sliding window. 
Lets consider few more examples, 
$$aaaaaabbbcaaa$$
The brute force approach i.e. checking all j ≥ i + 1 for each i. Will take O(n^2) time complexity.
Patterns: [patterns/Greedy](patterns/Greedy.md)[String](String)