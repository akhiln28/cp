#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <string>

#define max_n
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
            cout << 4 * a * a << endl;
        else if (a != b)
        {
            int x = max(a, b);
            int y = min(a, b);
            int side = max(2*y, x);
            cout << side * side << endl;
        }
    }
    return 0;
}
