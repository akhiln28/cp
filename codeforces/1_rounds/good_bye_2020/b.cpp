/*
    title: b.cpp
    author: Akhil
    date: 2020-12-30
    time: 20:12:59
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
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n;
        cin >> n;
        vector<int> line(2 * n + 2);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            line[x]++;
        }
        int ans = 0; 
        for (int i = 2 * n + 1; i >= 1; i--)
        {
            if (line[i] == 0 && line[i - 1]) line[i] = 1, line[i - 1]--;     
        }
        for (int i = 1; i < 2 * n + 2; i++)
        {
            ans += (line[i] > 0); 
        }
        cout << ans << endl;
    }
    return 0;
}