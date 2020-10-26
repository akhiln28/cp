/*
    title: D.cpp
    author: Akhil
    date: 2020-10-24
    time: 21:09:45
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

long long citizen(vector<vector<int>> &tree, int i, vector<int> &pop)
{
    if (tree[i].size() == 0) return pop[i]; 
    vector<long long> vals; 
    for (auto j : tree[i])
    {
        vals.push_back(citizen(tree, j, pop)); 
    }
    long long maxe = *max_element(vals.begin(), vals.end()); 
    long long req = 0; 
    for (auto i : vals) req += (maxe - i); 
    if (req >= pop[i]) return maxe;
    else return maxe + (pop[i] - req + vals.size() - 1)/vals.size(); 
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> tree(n); 
    for (int i = 0; i < n - 1; i++)
    {
        int p; cin >> p; 
        tree[p - 1].push_back(i + 1); 
    }
    vector<int> pop(n); 
    for (int i = 0; i < n; i++) cin >> pop[i]; 
    cout << citizen(tree, 0, pop) << endl;
    cout << citizen(tree, 1, pop) << endl;
    return 0;
}
