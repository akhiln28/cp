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
        int n; cin >> n; vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long sum = accumulate(v.begin(), v.end(), 0);
        if (*max_element(v.begin(), v.end()) > sum / 2) cout << "T" << endl;
        else
        {
            cout << (sum & 1 ? "T" : "HL") << endl;
        }   
    }
    return 0;
}