#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <map>
#include <climits>
#include <cmath>

#define max_n 1001

using namespace std;

int arr[max_n];

bool sorted(int *arr, int n)
{
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int mex(int *arr, int n)
{
    int mex = 0;
    map<int, int> mp;
    for (size_t i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (size_t i = 0; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            mex = i;
            break;
        }
    }
    return mex;
}

int notequal(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] != i)
            return i;
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> ans;
        while (sorted(arr, n) == false)
        {
            int MEX = mex(arr, n);
            int idx;
            if (MEX == n)
            {
                idx = notequal(arr, n);
                arr[idx] = n;
            }
            else
            {
                arr[MEX] = MEX;
                idx = MEX;
            }
            ans.push_back(idx + 1);
        }
        cout << ans.size() << endl;
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
