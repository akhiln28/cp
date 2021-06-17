# Rotate a Box Under Gravity | binarysearch

Created Time: Mar 01, 2021 8:33 AM
Do Date: Mar 01, 2021
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Source: https://binarysearch.com/problems/Rotate-a-Box-Under-Gravity
Status: done

You are given a two-dimensional list of strings `matrix`. Each element in matrix contains one of the following:

- `"."`, which means that the cell is empty.
- `"*"`, which means that the cell contains an obstacle.
- `"#"`, which means that the cell contains a small box.

You decide to rotate the matrix clockwise `90` degrees to see how the small boxes will fall under gravity. After rotating, each small box falls down until it lands on an obstacle, another small box, or the bottom of the big box. The obstacle does not fall under gravity.

Return the state of `matrix` after rotating it 90 degrees clockwise.

**Constraints**

- `0 ≤ n * m ≤ 100,000` where `n` is the number of rows and columns in `matrix`