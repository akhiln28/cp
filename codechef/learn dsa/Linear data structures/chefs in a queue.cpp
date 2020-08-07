#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

#define M 1000000007

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<int> st;
    long long ans = 1;

    for (size_t i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty() && v[i] < v[st.top()])
            {
                ans = (ans * (i - st.top() + 1)) % M;
                st.pop();
            }
            st.push(i);
        }
    }
    cout << ans << endl;
}