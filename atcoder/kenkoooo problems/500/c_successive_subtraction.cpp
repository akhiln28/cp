/*
    title: c_successive_subtraction.cpp
    author: Akhil
    date: 2020-10-15
    time: 13:38:23
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
    int n; cin >> n; 
    vector<int> pos, neg; 
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; 
        if (x > 0) pos.push_back(x); else neg.push_back(x); 
    }
    sort(pos.begin(), pos.end()); 
    sort(neg.begin(), neg.end()); 
    int ans; 
    if (pos.size() == 0)
    {
        ans = neg.back() - accumulate(neg.begin(), neg.end() - 1, 0); 
        cout << ans << endl;
        reverse(neg.begin(), neg.end()); 
        while (neg.size() >= 2)
        {
            int back = neg.back(); neg.pop_back(); 
            cout << neg[0] << " " << back << endl;
            neg[0] -= back; 
        }
        return 0; 
    }
    if (neg.size() == 0)
    {
        ans = accumulate(pos.begin() + 1, pos.end(), 0) - pos[0]; 
        cout << ans << endl;
        while (pos.size() > 2)
        {
            int back = pos.back(); pos.pop_back(); 
            cout << pos[0] << " " << back << endl;
            pos[0] -= back; 
        }
        cout << pos[1] << " " << pos[0] << endl;
        return 0; 
    }
    ans = accumulate(pos.begin(), pos.end(), 0) - accumulate(neg.begin(), neg.end(), 0);
    cout << ans << endl;
    while (pos.size() > 1)
    {
        int back = pos.back(); pos.pop_back(); 
        cout << neg[0] << " " << back << endl;
        neg[0] -= back; 
    }
    while (neg.size())
    {
        int back = neg.back(); neg.pop_back(); 
        cout << pos[0] << " " << back << endl;
        pos[0] -= back; 
    }
    return 0;
}
