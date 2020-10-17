#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin >> t;
    long long x, y, n;
    while(t--)
    {
        cin >> x >> y >> n;
        //k = k1 * x + y <= n
        // k1 = (n - y)/x;
        long long k1 = (n - y)/x;
        cout << k1 * x + y << endl;
    }
    return 0;

}

