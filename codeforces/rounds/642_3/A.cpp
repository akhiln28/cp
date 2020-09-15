#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n >= 3) cout << 2 * m << endl;
        if (n == 2) cout << m << endl;
        if (n == 1) cout << 0 << endl;
    }
    
    return 0;
}