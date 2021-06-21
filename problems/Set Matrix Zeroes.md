---
Created Time: Dec 01, 2020 11:51 PM
Do Date: Dec 29, 2020
Last edited time: May 11, 2021 9:07 AM
Points: 1500
Status: done
Tags: goldman sachs
---

# Set Matrix Zeroes

Store the column data in the first row. 
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) return;
        int n = matrix.size(), m = matrix[0].size();
        bool firstrow_zero = false;
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0) 
            {
                firstrow_zero = true;
                break;
            }
        }
        for (int j = 0; j < m; j++)
        {
            bool column_zero = false;
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == 0)
                {
                    column_zero = true;
                    break;
                }
            }
            if (column_zero) matrix[0][j] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            bool row_zero = false;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_zero = true;
                }
                if (matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (row_zero)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstrow_zero)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
    }
};
```
Patterns: [Array](Array.md)[Inplace](Inplace.md)