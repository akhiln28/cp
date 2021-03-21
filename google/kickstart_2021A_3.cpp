#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: kickstart_2021A_3.cpp
    author: Akhil
    date: 2021-03-21
    time: 10:09:38
    ==================================================
    Given a matrix containing integers.
    You can increase the value of integers.
    Minimum sum of increments to make difference between adjacent cells at most 1.
    3
    1 3
    3 4 3
    Ans = 0
    1 3
    3 0 0
    Ans = 3
    3 3
    0 0 0
    0 2 0
    0 0 0
    Ans = 4
    Consider few more examples
    Simple greedy simulation
    ========================
    In each iteration update each cell in the matrix based on its adjacent cells
    2 3 9
    6 4 2
    iteration 1:
    5 8 9
    6 5 8
    iteration 2:
    7 8 9
    6 7 8
    output
    7 8 9
    6 7 8
    Ans = 5 + 5 + 0 + 0 + 3 + 6 = 19
    Example 2
    14 1 1 1 1 15
    output - 14 13 12 13 14 15

    For simplicity consider an array of integers instead of matrix.
    14 1 2 9 7 2 15
    iteration 1:
    14 13 8 9 8 14 15
    iteration 2:
    14 13 12 9 13 14 15
    iteration 3:
    14 13 12 12 13 14 15

    Dynamic programming approach:
    computed (0, 0) -> (i, j)
    dp[i][j] = dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]
    Graph approach?:
*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int m, n; cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int> (n));
        vector<vector<int>> new_matrix(m, vector<int> (n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        vector<vector<int>> original(m, vector<int> (n));
        original = matrix;
        bool flag = false;
        while (flag == false)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int maxe = matrix[i][j] + 1;
                    if (i + 1 < m) maxe = max(maxe, matrix[i + 1][j]);
                    if (j + 1 < n) maxe = max(maxe, matrix[i][j + 1]);
                    if (i - 1 >= 0) maxe = max(maxe, matrix[i - 1][j]);
                    if (j - 1 >= 0) maxe = max(maxe, matrix[i][j - 1]);
                    new_matrix[i][j] = maxe - 1;
                }
            }
            flag = true;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i + 1 < m and abs(new_matrix[i][j] - new_matrix[i + 1][j]) > 1) {flag = false; break;}
                    if (j + 1 < n and abs(new_matrix[i][j] - new_matrix[i][j + 1]) > 1) {flag = false; break;}
                    if (i - 1 >= 0 and abs(new_matrix[i][j] - new_matrix[i - 1][j]) > 1) {flag = false; break;}
                    if (j - 1 >= 0 and abs(new_matrix[i][j] - new_matrix[i][j - 1]) > 1) {flag = false; break;}
                }
                if (flag == false) break;
            }
            if (flag) break;
            else matrix = new_matrix;
        }
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += new_matrix[i][j] - original[i][j];
            }
        }
        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}