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
        string s;
        cin >> s;
        int n = s.length();
        vector<int> prev(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') prev[i] = i;
            else prev[i] = (i ? prev[i - 1] : -1);
        }
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            int sum = 0; 
            for (int l = r; l >= 0 && r - l <= 18; l--)
            {
                if (s[l] == '0') continue;
                sum += 1 << (r - l);
                ans += sum <= (r - (l ? prev[l - 1] : -1));
            }
        }
        cout << ans << endl;
    }
}