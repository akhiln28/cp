#include <iostream>
#include <functional>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    long long t, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        if (a <= b) {
            cout << b << endl;
            continue;
        }
        if (c <= d && b < a)
        {
            cout << -1 << endl;
        }
        else
        {
            long long count = ceil((double)(a - b)/(c - d));
            cout << count * c + b << endl;
        }
    }
    return 0;
}