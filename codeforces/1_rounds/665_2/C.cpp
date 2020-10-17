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
        vector<int> v(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> v1(v);
        sort(v1.begin(), v1.end());
        int mine = v1[0];
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != v1[i] && v[i] % mine != 0) 
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}