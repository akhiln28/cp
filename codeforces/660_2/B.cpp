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
        int t2 = (int)ceil((float)n/4);
        int t1 = n - t2;
        for (size_t i = 0; i < t1; i++)
        {
            cout << 9;
        }
        for (size_t i = 0; i < t2; i++)
        {
            cout << 8;
        }
        cout << endl;
    }

    return 0;
}