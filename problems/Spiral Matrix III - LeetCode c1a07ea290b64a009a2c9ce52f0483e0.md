# Spiral Matrix III - LeetCode

Created Time: Feb 19, 2021 9:33 AM
Do Date: Feb 23, 2021
Last edited time: Feb 23, 2021 8:15 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb
Points: 1500
Pomos (25 mins): 2
Related To: Spiral%20Matrix%2059bb07ea77464b4881b0135bcd8e2e95.md
Source: https://leetcode.com/problems/spiral-matrix-iii/
Status: ok

On a 2 dimensional grid with `R` rows and `C` columns, we start at `(r0, c0)` facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)

Eventually, we reach all `R * C` spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

**Example 1:**

```
Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
```

![Spiral%20Matrix%20III%20-%20LeetCode%20c1a07ea290b64a009a2c9ce52f0483e0/Untitled.png](problems/Spiral%20Matrix%20III%20-%20LeetCode%20c1a07ea290b64a009a2c9ce52f0483e0/Untitled.png)

**Example 2:**

```
Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
```

![Spiral%20Matrix%20III%20-%20LeetCode%20c1a07ea290b64a009a2c9ce52f0483e0/Untitled%201.png](problems/Spiral%20Matrix%20III%20-%20LeetCode%20c1a07ea290b64a009a2c9ce52f0483e0/Untitled%201.png)

**Note:**

1. `1 <= R <= 100`
2. `1 <= C <= 100`
3. `0 <= r0 < R`
4. `0 <= c0 < C`

---

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans; 
        int n = 0; 
        int dx = 0, dy = 1;
        while (ans.size() != R * C)
        {
            for (int i = 0; i < n/2 + 1; i++)
            {
                if (r0 >= 0 and r0 < R and c0 >= 0 and c0 < C)
                {
                    ans.push_back({r0, c0}); 
                }
                r0 += dx, c0 += dy; 
            }
            // 0, 1 -> 1, 0 -> -1, 0 -> 0, 1
            int dt = dy; 
            dy = -dx; 
            dx = dt; 
            n++;
        }
        return ans; 
    }
};
```

#pending

I don't understand the following method, 

[[C++/Java/Python] 1,1,2,2,3,3 Steps - LeetCode Discuss](https://leetcode.com/problems/spiral-matrix-iii/discuss/158970/C%2B%2BJavaPython-112233-Steps)