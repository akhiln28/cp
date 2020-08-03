#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 200001

int arr[max_n];

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max_day = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool flag1 = arr[i] > max_day;
            bool flag2 = true;
            if (i + 1 < n)
            {
                flag2 = (arr[i] > arr[i + 1]);
            }
            if (flag1 && flag2)
                ans++;
            max_day = max(max_day, arr[i]);
        }
        cout << "case #" << l << ": " << ans << endl;
    }
    return 0;
}