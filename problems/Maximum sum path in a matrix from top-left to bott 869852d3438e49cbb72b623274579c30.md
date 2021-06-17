# Maximum sum path in a matrix from top-left to bottom-right - GeeksforGeeks

Created Time: Dec 26, 2020 10:22 AM
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1500
Relates: Path%20with%20Maximum%20gold%20f7c30ab252ee481d84aec8580cd1e660.md
Source: https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix-from-top-left-to-bottom-right/?ref=rp
Status: done
Tags: path cost, standard

Given a matrix **mat[][]** of dimensions **N * M**, the task is to find the path from the **top-left cell** (0, 0) to the **bottom-right cell** (N – 1, M – 1) of the given matrix such that sum of the elements in the path is maximum. The only moves allowed from any cell (i, j) of the matrix are **(i + 1, j)** or **(i, j + 1)**.