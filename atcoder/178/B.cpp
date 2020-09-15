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
    long long a, b, c, d; 
    cin >> a >> b >> c >> d;
    long long ans = -1e18;
    ans = max(ans, a * c); 
    ans = max(ans, a * d); 
    ans = max(ans, b * c); 
    ans = max(ans, b * d); 
    cout << ans << endl;
    return 0;
}