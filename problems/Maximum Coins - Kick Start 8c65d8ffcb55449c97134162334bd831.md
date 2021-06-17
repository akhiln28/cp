# Maximum Coins - Kick Start

Created Time: Mar 20, 2021 8:45 AM
Do Date: Mar 20, 2021
Last edited time: Mar 20, 2021 8:53 AM
Pattern: https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Pomos (25 mins): 1
Source: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a23
Status: done

![kickstart-fb.jpg](problems/Maximum%20Coins%20-%20Kick%20Start%208c65d8ffcb55449c97134162334bd831/kickstart-fb.jpg)

### Problem

Mike has a square matrix with **N** rows and **N** columns. Cell (i,j) denotes the cell present at row i and column j. Cell (1,1) denotes the top left corner of the matrix. Each cell has some amount of coins associated with it and Mike can collect them only if he visits that cell. **Ci,j** represents the number of coins in cell with row i and column j. From a cell (i,j), Mike can decide to go to cell (i+1,j+1) or cell (i-1,j-1), as long as the cell lies within the boundaries of the matrix and has not been visited yet. He can choose to start the journey from any cell and choose to stop at any point. Mike wants to maximize the number of coins he can collect. Please help him determine the maximum number of coins he can collect.

### Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case begins with a line containing the integer **N**. The next **N** lines contain **N** integers each. The j-th integer in the i-th line represents the number of coins **Ci,j** in cell (i,j).

### Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the maximum number of coins Mike can collect.

### Limits

Time limit: 20 seconds per test set.
 Memory limit: 1GB.
 1 ≤ **T** ≤ 100.
 0 ≤ **Ci,j** ≤ 107.

### Test Set 1

1 ≤ **N** ≤ 100.

### Test Set 2

1 ≤ **N** ≤ 103 in at most 10 cases.
 1 ≤ **N** ≤ 100 in all other cases.

### Sample

In Sample Case #1, the maximum number of coins collected can be 14, if Mike follows this path: (1,1) -> (2,2) -> (3,3)

In Sample Case #2, the maximum number of coins collected can be 9, if Mike follows this path: (2,3) -> (3,4).