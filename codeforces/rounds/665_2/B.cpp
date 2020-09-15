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
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int gain = 2 * min(z1, y2); 
        int t1 = (z1 - y2) > 0 ? (z1 - y2) : 0;
        int loss = ((t1 + x1) - z2) < 0 ? ((t1 + x1) - z2) * 2 : 0;
        cout << gain + loss << endl; 
    }

    return 0;
}