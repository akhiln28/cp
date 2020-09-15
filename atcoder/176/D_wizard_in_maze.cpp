#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>
#define max_n 1001

// #pending

using namespace std;


int maze[max_n][max_n];
int h, w; 

void explore(int i, int j, int idx)
{
    maze[i][j] = idx;
    vector<pair<int, int>> v{{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
    auto check = [](int i, int j) {
        return (i >= 0 && i < h) && (j >= 0 && j < w) && maze[i][j] == '.';
    };
    for (auto p : v)
    {
        if (check(p.first, p.second))
        {
            explore(p.first, p.second, idx);
        }
    }
}

int main()
{
    cin >> h >> w;
    int si, sj, di, dj; 
    cin >> si >> sj >> di >> dj;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char ch; cin >> ch;
            maze[i][j] = ch;
        }
    }
    int idx = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (maze[i][j] == '.')
                explore(i, j, idx++);
        }
    }
    vector<vector<int>> v(idx);
    auto check = [](int i, int j) {
        return (i >= 0 && i < h) && (j >= 0 && j < w);
    };
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (maze[i][j] == '#') continue;
            int idx = maze[i][j];
            for (int r = i - 2; r <= i + 2; r++)
            {
                for (int c = j - 2; c <= j + 2; c++)
                {
                    if (check(r, c))
                    {
                        
                    }
                }
                
            }
        }
    }
    
    return 0;
}