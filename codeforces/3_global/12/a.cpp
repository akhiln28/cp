/*
    title: a.cpp
    author: Akhil
    date: 2020-12-06
    time: 20:06:46
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
        int n; cin >> n; 
        string a; cin >> a; 
        string ans; 
        int count = 0; 
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != 't') ans += a[i]; 
            else count++; 
        }
        for (int i = 0; i < count; i++)
        {
            ans += 't';
        }
        
        cout << ans << endl;
    }
    return 0;
}
