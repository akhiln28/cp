#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <bitset>
#include <stdio.h>

#define max_a 4001

using namespace std;

int main()
{
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1); 
    vector<bitset<max_a>> cum_a(n + 1), cum_b(m + 1); 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cum_a[i][a[i]] = 1;
        cum_a[i] ^= cum_a[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        cum_b[i][b[i]] = 1;
        cum_b[i] ^= cum_b[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        l1--, l2--;
        cout << (cum_a[l1] ^ cum_a[r1] ^ cum_b[l2] ^ cum_b[r2]).count() << endl;
    }
}