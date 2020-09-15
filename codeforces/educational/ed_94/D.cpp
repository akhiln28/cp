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
        int n; cin >> n; 
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long ans = 0; 
        vector<int> lcount(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> rcount(n + 1, 0);
            for (int j = n - 1; j > i; j--)
            {
                ans += lcount[v[j]] * rcount[v[i]];
                rcount[v[j]]++;
            }
            lcount[v[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}