/*
    title: toy_blocks.cpp
    author: Akhil
    date: 2020-12-05
    time: 16:33:20
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
        long long n; cin >> n; 
        vector<long long> v(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i]; 
        }
        long long required = (n - 1) * (*max_element(v.begin(), v.end()));
        long long available = accumulate(v.begin(), v.end(), 0LL);
        long long ans = required - available; 
        if (ans < 0) ans = (ans % (n - 1)); 
        if (ans < 0) ans += n - 1; 
        cout << ans << endl;
    }
    return 0;
}