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

void Transform(vector<int> &ans, vector<int> &v1, vector<int> &v2, int idx)
{
    int i = idx;
    while (i >= 0 && v1[i] == v2[i])
        i--;
    if (i == -1)
        return;
    else
    {
        if (v1[0] != v1[i])
        {
            ans.push_back(1);
            v1[0] = 1 - v1[0];
        }
        ans.push_back(i + 1);
        vector<int> temp;
        for (int k = 0; k <= i; k++)
        {
            temp.push_back(1 - v1[k]);
        }
        reverse(temp.begin(), temp.end());
        for (int k = 0; k <= i; k++)
        {
            v1[k] = temp[k];
        }
        Transform(ans, v1, v2, i - 1);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n), ans;
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
        Transform(ans, v1, v2, v1.size() - 1);
        cout << ans.size() << " ";
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}