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

// #pending

int max_score(vector<int> &v, int i, int k, int z, bool right)
{
    if (k == 0) return 0; 
    int ans = 0; 
    if (right) return v[i + 1] + max_score(v, i + 1, k - 1, z, false);
    if (i < v.size() - 1) ans = max(ans, v[i + 1] + max_score(v, i + 1, k - 1, z, false));
    if (i > 0 && z > 0) ans = max(ans, v[i - 1] + max_score(v, i - 1, k - 1, z - 1, true));
    return ans;
}

int main()
{
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, k, z; cin >> n >> k >> z;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << v[0] + max_score(v, 0, k, z, false) << endl;
    }
}