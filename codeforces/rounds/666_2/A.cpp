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
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> alpha(26, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < v[i].length(); j++)
            {
                alpha[v[i][j] - 'a']++;
            }
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] % n != 0)
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}