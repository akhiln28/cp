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
    title: kickstart_2020G_2_maximum_coins.cpp
    author: Akhil
    date: 2021-03-21
    time: 08:24:42
    ==================================================
    Need to find the maximum of sum of elements in each cross diagonal
    1 2 5
    3 6 1
    12 2 7
    (3, 1) (2, 1) (1, 1) (1, 2) (1, 3)
    output: 14
*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n; cin >> n;
        vector<vector<int>> matrix(n, vector<int> (n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        long long ans = 0;
        int i = n - 1, j = 0;
        while (i >= 0)
        {
            long long temp_ans = 0;
            int i1 = i, j1 = j;
            while (i1 < n and j1 < n)
            {
                temp_ans += matrix[i1][j1];
                i1++, j1++;
            }
            ans = max(ans, temp_ans);
            i--;
        }
        i = 0, j = 1;
        while (j < n)
        {
            int i1 = i, j1 = j;
            long long temp_ans = 0;
            while (i1 < n and j1 < n)
            {
                temp_ans += matrix[i1][j1];
                i1++, j1++;
            }
            ans = max(ans, temp_ans);
            j++;
        }
        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}
