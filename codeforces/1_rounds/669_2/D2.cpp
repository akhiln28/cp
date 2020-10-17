#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int n; cin >> n; 
    vector<int> hs(n); 
    for (auto &h : hs) cin >> h;

    vector<int> l1(n, -1), l2(n, -1), r1(n, n), r2(n, n);

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty()) st.push(i);
        else if (hs[i] >= hs[st.top()]) l1[i] = st.top(), st.push(i);
        else 
        {
            while (st.size() and hs[i] < hs[st.top()]) st.pop();
            if (st.size()) l1[i] = st.top();
            st.push(i);
        }
    }
    while (st.size()) st.pop();
    for (int i = 0; i < n; i++)
    {
        if (st.empty()) st.push(i);
        else if (hs[i] <= hs[st.top()]) l2[i] = st.top(), st.push(i);
        else
        {
            while (st.size() and hs[i] > hs[st.top()]) st.pop();
            if (st.size()) l2[i] = st.top();
            st.push(i);
        }
    }
    while (st.size()) st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty()) st.push(i);
        else if (hs[i] >= hs[st.top()]) r1[i] = st.top(), st.push(i);
        else
        {
            while (st.size() and hs[i] < hs[st.top()]) st.pop();
            if (st.size()) r1[i] = st.top();
            st.push(i);
        }
    }
    while (st.size()) st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty()) st.push(i);
        else if (hs[i] <= hs[st.top()]) r2[i] = st.top(), st.push(i);
        else
        {
            while (st.size() and hs[i] > hs[st.top()]) st.pop();
            if (st.size()) r2[i] = st.top(); 
            st.push(i);
        }
    }

    vector<vector<int>> jumps(n);
    for (int i = 0; i < n; i++)
    {
        if (l1[i] >= 0) jumps[i].push_back(l1[i]);
        if (l2[i] >= 0) jumps[i].push_back(l2[i]);
        if (r1[i] < n) jumps[r1[i]].push_back(i);
        if (r2[i] < n) jumps[r2[i]].push_back(i);
    }

    vector<int> dp(n, n); dp[0] = 0; 
    for (int i = 1; i < n; i++)
    {
        for (auto j : jumps[i])
            dp[i] = min(dp[i], 1 + dp[j]);
    }
    cout << dp[n - 1] << endl;
    return 0; 
}