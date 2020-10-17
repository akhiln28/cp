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
    long long x, k, d; cin >> x >> k >> d; x = abs(x);
    if ((float)x/d > k) cout << abs(x - k*d) << endl;
    else if ((float)x/d < k)
    {
        int t1 = x/d; int alpha = (k - t1)/2; 
        int k1 = (k - 2*alpha), k2 = k1 + 2, k3 = k1 - 2;
        cout << min(abs(x - k1 * d), min(abs(x - k2 * d), abs(x - k3 * d))) << endl;
    } 
    else cout << abs(x - k * d) << endl;
}