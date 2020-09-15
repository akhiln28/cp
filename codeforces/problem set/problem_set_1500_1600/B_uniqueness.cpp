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
    int n; cin >> n;
    vector<int> v(n + 2); 
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    set<int> prefix, suffix;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        if (prefix.find(v[i]) == prefix.end())
        {
            if (i) prefix.insert(v[i]);
            for (int j = n + 1;; j--)
            {
                if (suffix.find(v[j]) == suffix.end() && prefix.find(v[j]) == prefix.end())
                {
                    suffix.insert(v[j]);
                    ans = min(ans, j - i - 1); 
                }
                else 
                {
                    suffix.clear();
                    break;
                }
            }
        }
        else break;
    }
    cout << ans << endl;
}