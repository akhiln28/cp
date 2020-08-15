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
    int T; cin >> T; 
    for (int t = 0; t < T; t++)
    {
        long long l, r, m; cin >> l >> r >> m;
        for (int i = l; i <= r; i++)
        {
            if (m % i >= 0 && m % i <= r - l && m - (m % i) > 0)
            {
                cout << i << " " << l + m % i << " " << l << endl;
                break;;
            }
            if (i - m % i >= 0 && i - m % i <= r - l)
            {
                cout << i << " " << l << " " << l + i - m % i << endl;
                break;
            }
        }
    }
    return 0;
}