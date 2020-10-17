#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s.push_back('$');
    int n = s.length(), logn = log2(s.length());

    vector<int> suffixes(n);
    for (size_t i = 0; i < n; i++)
    {
        suffixes[i] = i;
    }
    sort(suffixes.begin(), suffixes.end(), [&](int a, int b) -> bool {
        return s[a] < s[b];
    });

    cout << logn << endl;
    for (int k = 1; k <= logn + 1; k++)
    {
        // making the order of strings of length k - 1 (now suffixes has strings length k - 1);
        vector<int> order(n);
        for (size_t i = 0; i < n; i++)
        {
            order[suffixes[i]] = i;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << order[i] << " ";
        // }
        // cout << endl;
        sort(suffixes.begin(), suffixes.end(), [&](int a, int b) -> bool {
            int l1 = a, l2 = b,
                r1 = (a + (int)pow(2, k - 1)) % n,
                r2 = (b + (int)pow(2, k - 1)) % n;

            return (order[l1] < order[l2]) || (order[l1] == order[l2] && order[r1] < order[r2]);
        });
        // for (int i = 0; i < n; i++)
        // {
        //     cout << suffixes[i] << " ";
        // }
        // cout << endl;
    }

    return 0;
}