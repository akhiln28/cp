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
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        if (n <= 30) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            if (n == 36 || n == 40 || n == 44) cout << "6 10 15 " << n - 31 << endl;
            else cout << "6 10 14 " << n - 30 << endl;
        }
    }
    return 0;
}