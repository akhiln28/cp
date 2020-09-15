#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <set>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int gcd = v[0];
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, v[i]);
    }
    if (gcd != 1) 
    {
        cout << "not coprime" << endl;
        return 0; 
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        vector<int> p_factors;
        for (int j = 2; j * j <= v[i]; j++)
        {
            if (v[i] % j == 0)
            {
                p_factors.push_back(j);
                while (v[i] % j == 0) v[i] /= j;
            }
        }
        if (v[i] != 1) p_factors.push_back(v[i]);
        for (auto p : p_factors)
        {
            if (s.find(p) != s.end())
            {
                cout << "setwise coprime" << endl;
                return 0; 
            }
            else s.insert(p);
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}