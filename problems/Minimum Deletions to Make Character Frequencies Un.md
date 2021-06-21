---
Created Time: Jan 27, 2021 3:41 PM
Do Date: Jan 27, 2021
Last edited time: Mar 01, 2021 3:43 PM
Points: 1600
Pomos (25 mins): 2
Source: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
Status: ok
---

# Minimum Deletions to Make Character Frequencies Unique - LeetCode

A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.
Given a string `s`, return *the **minimum** number of characters you need to delete to make* `s` ***good**.*
The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.
**Example 1:**
```
Input: s = "aab"
Output: 0
Explanation: s is already good.
```
**Example 2:**
```
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```
**Example 3:**
```
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```
**Constraints:**
- `1 <= s.length <= 10^5`
- `s` contains only lowercase English letters.
---
Given a string, return the minimum number of characters to be removed so that the frequencies of all the remaining characters are unique?
---
```python
## we will at most 26 frequencies
## Simple greedy would work as shown below. 
## Sort given frequencies in descending order, we have 
5 4 4 3 3 2 -> 5 4 3 2 1 0
10 8 5 2 -> 10 8 5 2
prev = MAX
for i = 0 to n - 1:
	val = min(prev - 1, nums[i])
	ans += nums[i] - val
	prev = val
return ans
```
Patterns: [patterns/Greedy](patterns/Greedy.md)