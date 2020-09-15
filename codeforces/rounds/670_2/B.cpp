#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int T; cin >> T; 
    for (int t = 0; t < T; t++)
    {
        int n; cin >> n;
        vector<long long> neg, pos;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x; 
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        sort(neg.begin(), neg.end());
        sort(pos.rbegin(), pos.rend());
        long long ans = INT64_MIN;
        if (pos.size() >= 5) ans = max(ans, pos[0] * pos[1] * pos[2] * pos[3] * pos[4]);
        if (neg.size() >= 2 and pos.size() >= 3) ans = max(ans, neg[0] * neg[1] * pos[0] * pos[1] * pos[2]);
        if (neg.size() >= 4 and pos.size() >= 1) ans = max(ans, neg[0] * neg[1] * neg[2] * neg[3] * pos[0]);
        if (pos.size() == 4 and neg.size()) ans = max(ans, neg[neg.size() - 1] * pos[0] * pos[1] * pos[2] * pos[3]);
        else ans = max(ans, 0ll);
        if (pos.size() == 2 and neg.size() >= 3) ans = max(ans, neg[neg.size() - 1] * neg[neg.size() - 2] * neg[neg.size() - 3] * pos[0] * pos[1]);
        else ans = max(ans, 0ll);
        if (pos.size() == 0)
        {
            long long prod = 1;
            for (int i = neg.size() - 1; i >= neg.size() - 5; i--) prod *= neg[i];
            ans = max(ans, prod);
        }
        cout << ans << endl;
    }
}