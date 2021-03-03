/*
    title: a_buy_the_string.cpp
    author: Akhil
    date: 2020-11-28
    time: 17:20:45
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
        int n, c0, c1, h; cin >> n >> c0 >> c1 >> h; 
        string s; cin >> s; 
        int one = 0, zero = 0; 
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') one++; 
            else zero++;
        }
        
        cout << min({one * c1 + zero * c0, one * (c0 + h) + zero * c0, one * c1 + zero * (c1 + h)}) << endl;
    }
    return 0;
}
