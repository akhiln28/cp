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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int minAnd = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            minAnd = min(minAnd, a[i] & b[j]);
        }
        ans |= minAnd;
    }
    cout << ans << endl;
}