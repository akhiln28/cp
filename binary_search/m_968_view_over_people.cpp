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
    title: m_968_view_over_people.cpp
    author: Akhil
    date: 2021-03-20
    time: 08:38:19
*/

/*
    A person can see a movie, if the k people to right are shorter than him.
    For each person i, we need maximum height maxe in (i + 1, i + k).
        if maxe < height[i] then he can see the movie
        else he cannot see the movie
    What we want is sliding window maximum...
    ------------------------------------------------------------------
    Another way is to find the next greater than or equal to element to the right for every element. i.e. using stack.
    From right to left, the stack should be increasing.
*/

vector<int> solve(vector<int>& heights, int k) {
    stack<int> st;
    int n = heights.size();
    vector<int> nextgltright(n, n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty()) st.push(i);
        else if (heights[i] <= heights[st.top()])
        {
            nextgltright[i] = st.top();
            st.push(i);
        }
        else
        {
            while (st.size() and heights[i] > heights[st.top()])
            {
                st.pop();
            }
            if (st.size())
            {
                nextgltright[i] = st.top();
            }
            st.push(i);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nextgltright[i] == n) ans.push_back(i);
        else if (nextgltright[i] - i > k) ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> heights{9, 8, 7, 7, 4, 9};
    int k = 2;
    auto ret = solve(heights, k);
    for (auto e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}