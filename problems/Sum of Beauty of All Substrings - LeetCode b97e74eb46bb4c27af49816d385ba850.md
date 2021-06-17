# Sum of Beauty of All Substrings - LeetCode

Created Time: Mar 06, 2021 5:04 PM
Do Date: Mar 06, 2021
Last edited time: Mar 06, 2021 5:46 PM
Pattern: https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Points: 1200
Source: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
Status: done

The **beauty** of a string is the difference in frequencies between the most frequent and least frequent characters.

- For example, the beauty of `"abaacc"` is `3 - 1 = 2`.

Given a string `s`, return *the sum of **beauty** of all of its substrings.*

**Example 1:**

```
Input: s = "aabcb"
Output: 5
Explanation:The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```

**Example 2:**

```
Input: s = "aabcbaa"
Output: 17

```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.