/*
    title: d.cpp
    author: Akhil
    date: 2020-12-13
    time: 17:55:04
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
    int n, m; cin >> n >> m;
    vector<int> blues(m); 
    for (int i = 0; i < m; i++)
    {
        cin >> blues[i];
    }
    sort(blues.begin(), blues.end());
    blues.push_back(n + 1); 

    vector<int> gaps;
    int cur = 0; 
    for (int i = 0; i < blues.size(); i++)
    {
        int gap = blues[i] - cur - 1; 
        if (gap) gaps.push_back(gap); 
        cur = blues[i];
    }

    // for (int i = 0; i < gaps.size(); i++) cout << gaps[i] << " "; cout << endl;
    if (gaps.size() == 0)
    {
        cout << 0 << endl;
        return 0; 
    }
    int k = *min_element(gaps.begin(), gaps.end());
    int ans = 0; 
    for (int i = 0; i < gaps.size(); i++)
    {
        ans += (gaps[i] + k - 1)/k;
    }
    
    cout << ans << endl;
    return 0;
}
