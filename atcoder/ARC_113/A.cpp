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

int main()
{
    int k; cin >> k; 
    long long ans = 0; 
    for (long long i = 1; i <= k; i++)
    {
        for (long long j = 1; j <= k; j++)
        {
            int d = k/(i * j);
            ans += d; 
            if (d == 0) break; 
        }
    }
    cout << ans << endl;
    return 0;
}