# Search a 2D Matrix II

Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 26, 2020
Last edited time: Mar 31, 2021 9:00 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1500
Related To: Search%20a%202D%20Matrix%2077cdaa4be67d4ada94d24ee3cf9be8bd.md
Status: done

Write an efficient algorithm that searches for a `target` value in an `m x n` integer `matrix`. The `matrix` has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg](https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg)

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg](https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg)

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `109 <= matix[i][j] <= 109`
- All the integers in each row are **sorted** in ascending order.
- All the integers in each column are **sorted** in ascending order.
- `109 <= target <= 109`

---