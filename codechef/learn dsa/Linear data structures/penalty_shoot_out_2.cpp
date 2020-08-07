#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v(2 * n + 1);
        char ch;
        for (size_t i = 0; i < 2*n; i++)
        {
            cin >> ch;
            v[i + 1] = ch - '0';
        }
        int a = 0, b = 0, ans = 2 * n;
        for (size_t i = 1; i <= 2*n; i++)
        {
            if ((i & 1) && v[i]) a++;
            else if (!(i & 1) && v[i]) b++;

            if (a > b + ceil((float)(2*n - i)/2))
            {
                ans = i; break;
            }
            if (b > a + (2*n - i)/2)
            {
                ans = i; break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}