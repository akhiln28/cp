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
    title: d_friend_suggestions.cpp
    author: Akhil
    date: 2021-06-23
    time: 10:09:34
*/

class union_find
{
    vector<int> parent, size;
    int components;

    union_find(int n) : parent(n), size(n, 1)
    {
        components = n;
        iota(parent.begin(), parent.end(), 0);
    }

    // returns the group (parent) in which x belongs
    int find(int x)
    {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y)
    {
        int parentx = find(x), parenty = find(y);
        if (parentx == parenty) return false;
        if (size[parentx] > size[parenty])
        {
            parent[parenty] = parentx;
            size[parentx] += size[parenty];
        }
        else
        {
            parent[parentx] = parenty;
            size[parenty] += size[parentx];
        }
        return true;
    }
};


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> friendships(m, vector<int> (2));
    vector<vector<int>> blockships(k, vector<int> (2));
    for (int i = 0; i < m; i++)
    {
        cin >> friendships[i][0] >> friendships[i][1];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> blockships[i][0] >> blockships[i][1];
    }
    return 0;
}