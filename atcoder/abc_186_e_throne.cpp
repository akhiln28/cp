#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    consider the following examples n, s (initial position), k (step)
    example 1: 10, 4, 3
    the throne is at 0, takahashi is at 4
    4 -> 7 -> 0 i.e. two steps
    example 2: 10000, 6, 14
    6 -> 20 -> ... -> 6 + k * 14 -> 9988 -> 2 first round
    2 -> ... -> 2 + k * 14 -> 9996 -> 10 second round
    each round can be calculated as shown below
    s + k * count ~ n
    count = (n - s)/k;
    new position s = s + k * (count + 1);
*/

int main()
{
    int num_tests;
    cin >> num_tests;
    for (int test = 0; test < num_tests; test++)
    {
        long long n, s, k;
        cin >> n >> s >> k;
        int ans = 0;
        unordered_set<int> vis;
        vis.insert(s);
        for (int i = 0; i < 100; i++)
        {
            int count = (n - s)/k;
            s = (s + k * (count)) % n;
            ans += count;
            if (s == 0) break;
            s += k; ans++;
            cout << s << " " << ans << endl;
            if (vis.count(s))
            {
                ans = -1;
                break;
            }
            vis.insert(s);
        }
        cout << ans << endl;
    }

    return 0;
}