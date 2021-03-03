/*
    title: c.cpp
    author: Akhil
    date: 2020-12-30
    time: 20:47:49
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
        string str; 
        cin >> str; 
        int n = str.length(); 
        int ans = 0; 
        for (int i = 0; i < n; i++)
        {
            if ((i && str[i] == str[i - 1] && str[i - 1] != '9') || (i > 1 && str[i] == str[i - 2] && str[i - 2] != '9'))
            {
                ans++; 
                str[i] = '9'; 
            }
        }
        cout << ans << endl;
    }
    return 0;
}