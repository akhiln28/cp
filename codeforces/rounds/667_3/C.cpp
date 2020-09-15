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
        int n, x, y; cin >> n >> x >> y;
        int d = 1; 
        for (d = 1; d <= 50; d++)
        {
            if ((y - x) % d == 0 && n >= (y - x)/d + 1) break;
        }
        vector<int> ans;
        int rem = n - (y - x)/d - 1;
        for (int i = x - d; i > 0 && rem; i -= d)
        {
            ans.push_back(i), rem--;
        }
        reverse(ans.begin(), ans.end());
        ans.push_back(x);
        for (int i = x + d; i <= y; i += d)
        {
            ans.push_back(i);
        }
        if (rem > 0)
        {
            for (int i = y + d; rem; i += d)
            {
                ans.push_back(i), rem--;
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}