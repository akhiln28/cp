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

int diff(string s1, string s2)
{
    int ans = 0; 
    for (int i = 0; i < s1.length(); i++)
    {
        ans += s1[i] != s2[i];
    }
    return ans;
}

int main()
{
    string s, t; cin >> s >> t;
    int ans = INT_MAX;
    for (int i = 0; i < s.length() - t.length() + 1; i++)
    {
        ans = min(ans, diff(s.substr(i, t.length()), t));
    }
    cout << ans << endl;
    return 0;
}