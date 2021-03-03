/*
    title: d.cpp
    author: Akhil
    date: 2020-12-30
    time: 21:13:21
*/

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

int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n; cin >> n;
        // first is weight, second is degree
        vector<pair<int, int>> vertex(n, {0, 0}); 
        long long sum = 0; 
        for (int i = 0; i < n; i++)
        {
            cin >> vertex[i].first; 
            sum += vertex[i].first; 
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            int x, y; cin >> x >> y;
            vertex[x - 1].second++; 
            vertex[y - 1].second++;
        }
        sort(vertex.begin(), vertex.end()); 
        cout << sum << " "; 
        int ptr = n - 1; 
        for (int k = 0; k < n - 2; k++)
        {
            while (ptr >= 0 && vertex[ptr].second == 1) ptr--; 
            sum += vertex[ptr].first, vertex[ptr].second--; 
            cout << sum << " "; 
        }
        cout << endl;
    }
    return 0;
}