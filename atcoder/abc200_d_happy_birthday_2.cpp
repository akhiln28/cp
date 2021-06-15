#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: abc200_4.cpp
    author: Akhil
    date: 2021-05-08
    time: 17:43:08
    patterns: subset/subsequence, modulo, backtracking??
    ==================================================
    given a sequence of integers a1 to an. (n < 200)
    find if there are any two distinct sets of indices such that their modulo 200 is same? if yes print them
    in a modulo 200 world, find any two different sequences whose sum is equal..

    brute force: upto 2^200 combinations but we only need two combinations whose sum is same
    if there are such subsequences s1 and s2 such that sum(s1) = sum(s2)
    can we reduce them? to a smaller size

    examples
    the sum of any subset can be atmost 200, we can store the values??
    1 + 2 + 3 + 4 + .. + 99
    99 + 1 = 100
    100 + 101 + 102 + .. + 199
*/
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] % 200 == v[j] % 200)
            {
                flag = true;
                cout << "Yes" << endl;
                cout << 1 << " " << i + 1 << endl;
                cout << 1 << " " << j + 1 << endl;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (flag) break;
                vector<int> t{v[i] % 200, v[j] % 200, v[k] % 200};
                sort(t.begin(), t.end());
                do
                {
                    if ((t[0] + t[1]) % 200 == t[2])
                    {
                        flag = true;
                        cout << "Yes" << endl;
                        if (t[2] == v[i] % 200) {
                            cout << 1 << " " << i + 1 << endl;
                            cout << 2 << " " << j + 1 << " " << k + 1 << endl;
                        }
                        else if (t[2] == v[j] % 200) {
                            cout << 1 << " " << j + 1 << endl;
                            cout << 2 << " " << i + 1 << " " << k + 1 << endl;
                        }
                        else if (t[2] == v[k] % 200) {
                            cout << 1 << " " << k + 1 << endl;
                            cout << 2 << " " << i + 1 << " " << j + 1 << endl;
                        }
                        if (flag) break;
                    }
                } while (next_permutation(t.begin(), t.end()));
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (flag == false)
        cout << "No" << endl;
    return 0;
}