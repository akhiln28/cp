#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        stack<long long> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty()) st.push(v[i]);
            else if (v[i] > 0) st.push(v[i]);
            else
            {
                long long t = 0; 
                while (st.size() && st.top() > 0)
                {
                    t += st.top(), st.pop();
                }
                st.push(t + v[i]);
            }
        }
        long long ans = 0;
        while (st.size())
        {
            if (st.top() < 0) break;
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
}