# Minimum Length of String After Deleting Similar Ends - LeetCode

Created Time: Feb 08, 2021 8:13 AM
Do Date: Feb 08, 2021
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Source: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
Status: done

Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`. You are asked to apply the following algorithm on the string any number of times:

1. Pick a **non-empty** prefix from the string `s` where all the characters in the prefix are equal.
2. Pick a **non-empty** suffix from the string `s` where all the characters in this suffix are equal.
3. The prefix and the suffix should not intersect at any index.
4. The characters from the prefix and suffix must be the same.
5. Delete both the prefix and the suffix.

Return *the **minimum length** of* `s` *after performing the above operation any number of times (possibly zero times)*.

**Example 1:**

```
Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.

```

**Example 2:**

```
Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".
```

**Example 3:**

```
Input: s = "aabccabba"
Output: 3
Explanation: An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".

```

**Constraints:**

- `1 <= s.length <= 105`
- `s` only consists of characters `'a'`, `'b'`, and `'c'`.