#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <map>

#define max_n 100
using namespace std;

int main()
{
    int t, n, m, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        int t1 = (m > n/k) ? (m - n/k) : 0;
        int t2 = ceil((float)t1/(k - 1));
        cout << min(m, n/k) - t2 << endl;
    }
    
    return 0;
}