/*
    title: b_color_the_fence.cpp
    author: Akhil
    date: 2020-10-06
    time: 16:12:23
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
    int v; cin >> v;
    vector<int> w(9); 
    for (int i = 0; i < 9; i++)
    {
        cin >> w[i]; 
    }
    int mine = 1e6, min_digit; 
    for (int i = 0; i < 9; i++)
    {
        if (mine > w[i]) mine = w[i], min_digit = i + 1;
    }
    if (v < mine)
    {
        cout << -1 << endl;
        return 0; 
    }
    int num_digits = v/mine; 
    vector<int> ans(num_digits, min_digit);
    int rem = v - num_digits * mine; 
    for (int i = 0; i < num_digits; i++)
    {
        for (int j = 9; j > ans[i]; j--)
        {
            if (rem >= w[j - 1] - w[ans[i] - 1])
            {
                rem -= (w[j - 1] - w[ans[i] - 1]); 
                ans[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < num_digits; i++) cout << ans[i];
    cout << endl;
    return 0;
}
