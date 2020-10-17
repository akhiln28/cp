#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k, x; cin >> n >> k;
        vector<int> v(n), left(n, 1), right(n, 1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
        }
        sort(v.begin(), v.end());
        int p1 = 0, p2 = 0; 
        while (p1 < n)
        {
            while (p2 < n && v[p2] - v[p1] <= k) p2++;
            right[p1] = p2 - p1, p1++;
        }
        p1 = n - 1, p2 = n - 1;
        while (p1 >= 0)
        {
            while (p2 >= 0 && v[p1] - v[p2] <= k) p2--;
            left[p1] = p1 - p2, p1--;
        }
        // prefix maximum of left
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], left[i]);
        }
        
        // suffix maximum of right
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i], right[i + 1]);
        }
        int ans = right[0];
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, left[i] + right[i + 1]);
        }
        ans = max(ans, left[n - 1]);
        cout << ans << endl;
    }

    return 0;
}