# Game of Life - Leetcode

Created Time: Feb 09, 2021 8:24 AM
Do Date: Feb 09, 2021
Last edited time: Feb 22, 2021 9:57 PM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/game-of-life/
Status: done

According to [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state: **live** (represented by a `1`) or **dead** (represented by a `0`). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the `m x n` grid `board`, return *the next state*.

**Example 1:**

![Game%20of%20Life%20-%20Leetcode%2012b4de9b345a4547bc1e7a8c191eaed6/grid1.jpg](grid1.jpg)

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**Example 2:**

![Game%20of%20Life%20-%20Leetcode%2012b4de9b345a4547bc1e7a8c191eaed6/grid2.jpg](grid2.jpg)

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 25`
- `board[i][j]` is `0` or `1`.

**Follow up:**

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

---

With extra space the question is straight forward. 

Each cell can have either < 2, 2, 3, > 3 neighbors. Four cases. Storing the count in the cell itself. 

```jsx
class Solution {
public:
    int count_nbs(vector<vector<int>>& board, int i, int j)
    {
        int n = board.size(), m = board[0].size();
        int ans = 0; 
        for (int r = i - 1; r <= i + 1 and r < n; r++)
        {
            for (int c = j - 1; c <= j + 1 and c < m; c++)
            {
                if (r < 0 or c < 0 or (r == i and c == j)) continue; 
                ans += board[r][c] % 2;
            }
        }
        return ans; 
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(); 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = 2 * count_nbs(board, i, j) + board[i][j]; 
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = board[i][j] / 2; 
                if (count < 2) board[i][j] = 0;
                else if (count > 3) board[i][j] = 0;
                else if (count == 3) board[i][j] = 1;
                else board[i][j] = board[i][j] % 2; 
            }
        }
    }
};
```