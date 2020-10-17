#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

// https://codeforces.com/problemset/problem/1393/B

int min_replacements(string s, char ch)
{
    if (!s.length()) return 0;
    if (s.length() == 1) return (s[0] != ch);

    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++)
    {
        left += (i < s.length() / 2 && s[i] == ch);
        right += (i >= s.length() / 2 && s[i] == ch);
    }
    int ans1 = s.length() / 2 - left + min_replacements(s.substr(s.length() / 2, s.length() / 2), ch + 1);
    int ans2 = s.length() / 2 - right + min_replacements(s.substr(0, s.length() / 2), ch + 1);
    return min(ans1, ans2);
}

int main()
{
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << min_replacements(s, 'a') << endl;
    }
    return 0;
}