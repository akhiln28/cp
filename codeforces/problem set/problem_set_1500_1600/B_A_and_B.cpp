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

/*
    DATE: 16-08-2020
    TIME: 21:19:02
    SOURCE: https://codeforces.com/problemset/problem/1278/B
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int n = ceil(sqrt(2 * abs(a - b)));
        while (n >= 0 && n * (n + 1) >= 2 * abs(a - b))
            n--;
        n++;
        if ((a - b) % 2 == 0)
            cout << min(n + (4 - n % 4) % 4, n + 3 - n % 4)  << endl;
        else
        {
            cout << min(n + (5 - n % 4) % 4, n + (6 - n % 4) % 4) << endl;
        }
    }
    return 0;
}
