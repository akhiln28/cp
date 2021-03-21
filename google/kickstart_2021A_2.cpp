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
    title: kickstart_2021A_2.cpp
    author: Akhil
    date: 2021-03-21
    time: 09:35:05
    ==================================================
    Given a binary matrix of zeroes and ones.
    Find the number of L shapes.
    2
    4 3
    1 0 0
    1 0 1
    1 0 0
    1 1 0
    6 4
    1 0 0 0
    1 0 0 1
    1 1 1 1
    1 0 1 0
    1 0 1 0
    1 1 1 0

*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int m, n; cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int> (n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        vector<vector<int>> prefv(m, vector<int> (n));
        vector<vector<int>> prefh(m, vector<int> (n));
        vector<vector<int>> suffv(m, vector<int> (n));
        vector<vector<int>> suffh(m, vector<int> (n));
        for (int j = 0; j < n; j++)
        {
            prefv[0][j] = matrix[0][j];
            for (int i = 1; i < m; i++)
            {
                if (matrix[i][j]) prefv[i][j] = prefv[i - 1][j] + matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            prefh[i][0] = matrix[i][0];
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j]) prefh[i][j] = prefh[i][j - 1] + matrix[i][j];
            }
        }
        for (int j = 0; j < n; j++)
        {
            suffv[m - 1][j] = matrix[m - 1][j];
            for (int i = m - 2; i >= 0; i--)
            {
                if (matrix[i][j]) suffv[i][j] = suffv[i + 1][j] + matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            suffh[i][n - 1] = matrix[i][n - 1];
            for (int j = n - 2; j >= 0; j--)
            {
                if (matrix[i][j]) suffh[i][j] = suffh[i][j + 1] + matrix[i][j];
            }
        }
        auto count = [](int a, int b){
            // number of l shapes between lengths a and b
            // 2 ... a -> 4 ... min(2 * a, b) => min(b - )
            // if (b >= 2 * a) a - 1
            // else b/2 - 1
            return (max(0, min(b/2, a) - 1) + max(0, min(a/2, b) - 1));
        };
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a = prefh[i][j], b = prefv[i][j], c = suffh[i][j], d = suffv[i][j];
                // cout << a << " " << b << " " << c << " " << d << endl;
                ans += count(a, b) + count(b, c) + count(c, d) + count(d, a);
            }
        }
        // cout << "=========" << endl;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << prefh[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=========" << endl;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << prefv[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=========" << endl;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << suffh[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=========" << endl;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << suffv[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}