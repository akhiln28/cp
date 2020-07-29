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
        string s = "abcdefghijklmnopqrstuvwxyz";
        int k = 0;
        vector<string> strings(n + 1, "");

        int length0 = v[0];
        for (size_t i = 0; i < length0; i++)
        {
            strings[0] += s[k % 26];
            k++;
        }

        for (size_t i = 1; i < n; i++)
        {
            strings[i] += strings[i - 1].substr(0, v[i - 1]);
            if (v[i] > v[i - 1])
            {
                for (size_t j = 0; j < v[i] - v[i - 1]; j++)
                {
                    strings[i] += s[k % 26];
                    k++;
                }
            }
        }
        strings[n] = strings[n - 1].substr(0, v[n - 1]);
        for (size_t i = 0; i < n + 1; i++)
        {
            strings[i] += s[k % 26];
            k++;
            cout << strings[i] << endl;
        }
    }

    return 0;
}