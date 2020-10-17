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

int maxlength_period2(char ch1, char ch2, string &s)
{
    bool flag;
    int i = 0, ans = 1;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ch1)
        {
            flag = true;
            break;
        }
        if (s[i] == ch2)
        {
            flag = false;
            break;
        }
    }

    for (int j = i + 1; j < s.length(); j++)
    {
        if (flag == true && s[j] == ch2)
        {
            flag = false;
            ans++;
        }
        else if (flag == false && s[j] == ch1)
        {
            flag = true;
            ans++;
        }
    }
    if (ans & 1)
        ans--;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        for (char ch : s)
        {
            mp[ch]++;
        }
        int t1 = 0;
        for (auto it : mp)
        {
            if (t1 < it.second)
            {
                t1 = it.second;
            }
        }
        int max1 = t1, max2 = 0;
        for (char ch1 = '0'; ch1 <= '9'; ch1++)
        {
            for (char ch2 = ch1; ch2 <= '9'; ch2++)
            {
                max2 = max(max2, maxlength_period2(ch1, ch2, s));
            }
        }
        // cout << max1 << " " << max2 << endl;
        cout << s.length() - max(max1, max2) << endl;
    }

    return 0;
}