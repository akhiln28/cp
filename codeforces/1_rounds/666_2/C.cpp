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
    long long n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << -v[0] << endl;
    }
    else
    {
        cout << 1 << " " << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << -v[i] * n << endl;
        }
        cout << 1 << " " << n - 1 << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << v[i] * (n - 1) << endl;
        }
        cout << n << " " << n << endl;
        cout << v[n - 1] * (n - 1) << endl;
    }
    
    return 0;
}