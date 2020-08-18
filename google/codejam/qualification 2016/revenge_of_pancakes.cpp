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

int main()
{
    int T;
    cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (size_t i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
                ans++;
        }
        if (s[s.length() - 1] == '-')
            ans++;
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }

    return 0;
}