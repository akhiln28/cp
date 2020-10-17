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
        int n;
        cin >> n;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        bool flag_ans = false;
        int i1, j, k;
        for (int i = 1; i <= n - 2; i++)
        {
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
            {
                flag_ans = true;
                i1 = i;
                j = i + 1;
                k = i + 2;
            }
        }
        if (flag_ans)
        {
            cout << "YES" << endl;
            cout << i1 << " " << j << " " << k << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}