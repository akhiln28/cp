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
        int l, r;
        cin >> l >> r;
        if (r < 2 * l)
        {
            cout << "-1 -1" << endl;
        }
        else
            cout << l << " " << 2 * l << endl;
    }

    return 0;
}