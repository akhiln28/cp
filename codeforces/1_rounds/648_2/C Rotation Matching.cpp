#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>

#define max_n 200001

using namespace std;

int a[max_n];
int b[max_n];


// this is very interesting, i am writing from my ipad using the cosmic byte keyboard
int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] - b[i];
    }
    //////////////////////
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            a[i] += n;
        }
    }//////////////////////
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    int ans_max = INT32_MIN;
    for (auto i : mp)
    {
        ans_max = max(ans_max, i.second);
    }
    cout << ans_max << endl;
    return 0;
}
