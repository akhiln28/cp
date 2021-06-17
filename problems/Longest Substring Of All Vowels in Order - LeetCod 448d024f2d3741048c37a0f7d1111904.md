# Longest Substring Of All Vowels in Order - LeetCode

Created Time: Apr 27, 2021 7:31 AM
Day Completed: https://www.notion.so/25-April-21-05fc8c658db34203ba20cd41c1899919
Last edited time: Apr 27, 2021 7:50 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Source: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
Status: done

![https://leetcode.com/static/images/LeetCode_Sharing.png](https://leetcode.com/static/images/LeetCode_Sharing.png)

---

A string is considered **beautiful** if it satisfies the following conditions:

- Each of the 5 English vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`) must appear **at least once** in it.
- The letters must be sorted in **alphabetical order** (i.e. all `'a'`s before `'e'`s, all `'e'`s before `'i'`s, etc.).

For example, strings `"aeiou"` and `"aaaaaaeiiiioou"` are considered **beautiful**, but `"uaeio"`, `"aeoiu"`, and `"aaaeeeooo"` are **not beautiful**.

Given a string `word` consisting of English vowels, return *the **length of the longest beautiful substring** of* `word`*. If no such substring exists, return* `0`.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**

```
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
```

**Example 2:**

```
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.

```

**Example 3:**

```
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.

```

**Constraints:**

- `1 <= word.length <= 5 * 105`
- `word` consists of characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

---