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
    int x, n;
    cin >> x >> n;
    vector<int> v(101, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[a] = 1;
    }
    int diff = INT_MAX, ans;
    for (int i = 101; i >= 0; i--)
    {
        if (!v[i])
        {
            if (diff >= abs(i - x))
            {
                diff = abs(i - x);
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
