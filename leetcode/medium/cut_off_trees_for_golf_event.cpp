/*
    title: Cut Off Trees for Golf Event.cpp
    author: Akhil
    date: 2020-10-02
    time: 18:51:23
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

class Solution {
public:
    bool check(vector<vector<int>> &forest, int i, int j)
    {
        int n = forest.size(), m = forest[0].size(); 
        return (i >= 0 and i < n and j >= 0 and j < m and forest[i][j] != 0); 
    }
    
    int dist(vector<vector<int>> &forest, pair<int, int> s, pair<int, int> e)
    {
        int n = forest[0].size(); 
        if (e == s) return 0; 
        unordered_map<int, int> dis; 
        dis[s.first * n + s.second] = 0; 
        queue<pair<int, int>> q;
        q.push(s); 
        int count = 0; 
        while (q.size())
        {
            count++; 
            cout << count << endl;
            auto p = q.front(); q.pop();  
            vector<pair<int, int>> t{{p.first, p.second - 1}, {p.first, p.second + 1}, {p.first - 1, p.second}, {p.first + 1, p.second}}; 
            for (auto x : t)
            {
                if (check(forest, x.first, x.second) and dis.find(x.first * n + x.second) == dis.end())
                {
                    dis[x.first * n + x.second] = 1 + dis[p.first * n + p.second]; 
                    if (x == e) return dis[x.first * n + x.second];
                    q.push(x); 
                }
            }
        }
        return -1; 
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        map<int, pair<int, int>> mp; 
        for (int i = 0; i < forest.size(); i++)
        {
            for (int j = 0; j < forest[0].size(); j++)
            {
                if (forest[i][j] == 0) continue; 
                mp[forest[i][j]] = {i, j}; 
            }
        } 
        pair<int, int> prev{0,0}; 
        int ans = 0; 
        for (auto [h, loc] : mp)
        {
            int d = dist(forest, loc, prev); 
            if (d == -1) return -1; 
            ans += d; 
            prev = loc; 
        }
        return ans; 
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> forest(n, vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> forest[i][j];
    }
    Solution s; 
    cout << s.cutOffTree(forest) << endl;
    return 0; 
}