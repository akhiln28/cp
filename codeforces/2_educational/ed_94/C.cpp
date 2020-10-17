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
        string s;
        cin >> s;
        int x;
        cin >> x;
        auto check = [s](int i) {
            return (i >= 0 && i < s.length());
        };
        vector<int> ans(s.length(), 1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                if (check(i + x))
                    ans[i + x] = 0;
                if (check(i - x))
                    ans[i - x] = 0;
            }
        }
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                bool f1 = (check(i - x) && ans[i - x] == 1);
                bool f2 = (check(i + x) && ans[i + x] == 1);
                if (f1 + f2 == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}