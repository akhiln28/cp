#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long i = n / 2;
        cout << 8 * i * (i + 1) * (2 * i + 1) / 6 << endl;
    }

    return 0;
}