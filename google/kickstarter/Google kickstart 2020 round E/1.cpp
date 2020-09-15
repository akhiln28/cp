#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0, count = 0, prev = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - v[i - 1] == prev) 
            {
                count++;
            }
            else
            {
                ans = max(ans, count);
                prev = v[i] - v[i - 1];
                count = 1;
            }
        }
        ans = max(ans, count);
        cout << "Case #" << t << ": " << ans + 1 << endl;
    }
}
