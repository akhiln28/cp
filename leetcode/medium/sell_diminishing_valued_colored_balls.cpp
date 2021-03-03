/*
    title: sell_diminishing_valued_colored_balls.cpp
    author: Akhil
    date: 2020-11-08
    time: 13:03:45
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
#include <set>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    set<int, greater<int>> s;
    for (size_t i = 0; i < 100; i++)
    {
        s.insert(100 - i); 
    }
    for (auto i : s) cout << i << " "; 
    cout << endl;
    return 0;
}
