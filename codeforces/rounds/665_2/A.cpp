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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n >= k)
        {
            if ((n + k) % 2 == 0)
            {
                cout << 0 << endl;
            }else cout << 1 << endl;
        }
        else
        {
            cout << k - n << endl;
        }
    }
    return 0;
}