# Search a 2D Matrix

Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 26, 2020
Last edited time: Mar 31, 2021 9:00 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1500
Relates: Search%20a%202D%20Matrix%20II%20ba94d1c9e77f4a1cae811ede2d124828.md
Status: done

Write an efficient algorithm that searches for a value in an `m x n` matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/05/mat.jpg](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `104 <= matrix[i][j], target <= 104`