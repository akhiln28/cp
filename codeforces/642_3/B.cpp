#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <algorithm>
#define max_n 30

using namespace std;

int a[max_n], b[max_n];

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        long sum = accumulate(a, a + n, 0);
        long x = accumulate(a, a + k, 0), y = accumulate(b, b + k, 0);
        cout << sum + max(x, y) - x << endl;
    }
    return 0;
}