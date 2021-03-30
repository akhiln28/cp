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
    title: gcj_2021_0_reversort.cpp
    author: Akhil
    date: 2021-03-30
    time: 07:54:25
    ==================================================
    Find the total cost of the reverse operation in reverse sort
*/

int reversort(vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int j = min_element(v.begin() + i, v.end()) - v.begin();
        ans += j - i + 1;
        reverse(v.begin() + i, v.begin() + j + 1);
    }
    return ans;
}
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << "Case #" << case_num << ": " << reversort(v) << endl;
    }
    return 0;
}