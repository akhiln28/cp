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
    title: abc201_c_secret_number.cpp
    author: Akhil
    date: 2021-05-17
    time: 09:38:11
    ==================================================
    I think this is a brute force question. Which I hate
*/

int fact(int n)
{
    if (n == 0 or n == 1) return 1;
    return n * fact(n - 1);
}
int main()
{
    string s;
    cin >> s;
    int o = 0, x = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'o') o++;
        else if (s[i] == 'x') x++;
    }
    if (o > 4)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}