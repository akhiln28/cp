# Word Search

Created Time: Jan 12, 2021 8:53 PM
Do Date: Jan 13, 2021
Last edited time: Mar 01, 2021 8:43 AM
Pattern: https://www.notion.so/DFS-ba39c3dceb894d178f88767d81fa001a
Points: 1500
Relates: Word%20Search%20II%205992ad02621b424c9092f3e9d26d7e43.md, Word%20Search%20III%2028f3cdb3e6b34189beb8ee5784b33ecd.md
Source: leetcode.com/problems/word-search
Status: done

Given an `m x n` `board` and a `word`, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/04/word2.jpg](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:**

![https://assets.leetcode.com/uploads/2020/10/15/word3.jpg](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

**Constraints:**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 200`
- `1 <= word.length <= 10^3`
- `board` and `word` consists only of lowercase and uppercase English letter

---