#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>

#define max_n 100
using namespace std;


int arr[max_n];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ans = INT16_MAX;
        for (int i = 1; i < n; i++)
        {
            ans = min( ans, arr[i] - arr[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
