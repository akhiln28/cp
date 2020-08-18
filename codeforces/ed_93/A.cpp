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
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++)
    {
        int n; cin >> n; 
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (v[0] + v[1] <= v[n - 1])
        {
            cout << "1 2 " << n << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
    return 0;
}