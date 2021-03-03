/*
    title: e.cpp
    author: Akhil
    date: 2020-11-08
    time: 18:12:56
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int h, w; cin >> h >> w; 
    vector<vector<int>> mat(h, vector<int> (w)); 
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b; 
        mat[a - 1][b - 1] = 1; 
    }
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; 
        mat[a - 1][b - 1] = -1; 
    }
    // row - right
    for (int i = 0; i < h; i++)
    {
        bool flag = false; 
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 1) flag = true; 
            else if (mat[i][j] == -1) flag = false; 
            else if (flag) mat[i][j] = 2; 
        }
        flag = false; 
        for (int j = w - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1) flag = true; 
            else if (mat[i][j] == -1) flag = false; 
            else if (flag) mat[i][j] = 2; 
        }
    }
    // col - down
    for (int j = 0; j < w; j++)
    {
        bool flag = false; 
        for (int i = 0; i < h; i++)
        {
            if (mat[i][j] == 1) flag = true; 
            else if (mat[i][j] == -1) flag = false; 
            else if (flag) mat[i][j] = 2; 
        }
        flag = false; 
        for (int i = h - 1; i >= 0; i--)
        {
            if (mat[i][j] == 1) flag = true; 
            else if (mat[i][j] == -1) flag = false; 
            else if (flag) mat[i][j] = 2; 
        }
    }
    int ans = 0; 
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans += (mat[i][j] > 0);
        }
    }
    cout << ans << endl;
    return 0;
}
