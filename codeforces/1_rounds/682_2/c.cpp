/*
    title: c.cpp
    author: Akhil
    date: 2020-11-14
    time: 11:47:55
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m)); 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j]; 
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i and mat[i][j] == mat[i - 1][j])
                {
                    mat[i][j]++;
                }
            }
        }
        
    }
    return 0;
}
