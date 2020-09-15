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

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s; cin >> s;
        vector<int> v;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' && count)
            {
                v.push_back(count), count = 0;
            }
            else if (s[i] == '1') count++;
        }
        if (count)
        {
            v.push_back(count);
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (!(i & 1))
                ans += v[i];
        }
        cout << ans << endl;
    }
    return 0;
}