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
    title: abc_199_c.cpp
    author: Akhil
    date: 2021-04-24
    time: 17:49:19
    ==================================================
    given a string of length 2n, you have two types of operations, 1 -> given (a, b) swap the values at a, and b. 2 -> swap the first half with the second half.
    abcdef
    1 1 2 -> bacdef
    2 - - -> defbac
    1 2 4 -> dbfeac
    2 - - -> eacdbf

    (123456) -> (456123) -> (2,4) -> (416523) -> (523416) -> (1,5) -> (123456)
    if (i > n) i -> i + n
    else i -> i - n
*/
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    bool flag = false;
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            if (!flag) swap(s[a - 1], s[b - 1]);
            else swap(s[(a - 1 + n) % (2 * n)], s[(b - 1 + n) % (2 * n)]);
        }
        else
        {
            flag = 1 - flag;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            swap(s[i], s[i + n]);
        }
    }
    cout << s << endl;
    return 0;
}