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

int cum_sum(vector<int> cum, int i, int j)
{
    if (i > 0 && j < cum.size()) return cum[j] - cum[i - 1];
    else if (i == 0 && j < cum.size()) return cum[j];
    else return -1;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        vector<int> v(n), cum(n); 
        char ch;
        for (int i = 0; i < n; i++)
        {
            cin >> ch; 
            v[i] = ch - '0';
        }
        cum[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            cum[i] = cum[i - 1] + v[i];
        }
        
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j <= v[i] - 1; j++)
            {
                ans += (cum_sum(cum, i - j, i + v[i] - 1 - j) == v[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}