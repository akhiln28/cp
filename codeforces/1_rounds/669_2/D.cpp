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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int prev = 0, maxe = INT_MIN, mine = INT_MAX, jumps = 0;

    for (int i = 1; i < n; i++)
    {
        if (!is_possible(maxe, mine, prev, i, v)) {jumps++, prev = --i; maxe = INT_MIN, mine = INT_MAX;}
        maxe = max(maxe, v[i]), mine = min(mine, v[i]);
    }
    cout << jumps + 1 << endl;
    return 0;
}