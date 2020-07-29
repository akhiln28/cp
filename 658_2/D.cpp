#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

void convertToAllZeroes(vector<int> &ans, vector<int> &v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
        {
            ans.push_back(i);
        }
    }
    if (v[v.size() - 1] == 1)
        ans.push_back(v.size());
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        char ch;
        for (size_t i = 0; i < n; i++)
        {
            cin >> ch;
            v1[i] = ch - '0';
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> ch;
            v2[i] = ch - '0';
        }

        vector<int> ans1, ans2;
        convertToAllZeroes(ans1, v1);
        convertToAllZeroes(ans2, v2);
        reverse(ans2.begin(), ans2.end());
        cout << ans1.size() + ans2.size() << " " << endl;
        for (size_t i = 0; i < ans1.size(); i++)
        {
            cout << ans1[i] << " ";
        }
        for (size_t i = 0; i < ans2.size(); i++)
        {
            cout << ans2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}