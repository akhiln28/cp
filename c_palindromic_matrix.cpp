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
    title: c_palindromic_matrix.cpp
    author: Akhil
    date: 2021-06-22
    time: 09:01:26
    ==================================================
*/
int main()
{
    int H, W;
    cin >> H >> W;
    vector<int> alpha(26);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char ch;
            cin >> ch;
            alpha[ch - 'a']++;
        }
    }
    int count_odd = 0, count_even = 0;
    for (int i = 0; i < alpha.size(); i++)
    {
        if (alpha[i] % 2 != 0)
        {
            count_odd++;
        }
        else if (alpha[i] % 4 != 0)
        {
            count_even++;
        }
    }
    int even_limit = 0;
    int odd_limit = 0;
    if (H & 1 and W & 1)
    {
        // both are odd
        even_limit = H/2 + W/2;
        odd_limit = 1;
    }
    else if (H & 1)
    {
        even_limit = W/2;
    }
    else if (W & 1)
    {
        even_limit = H/2;
    }

    if (count_even > even_limit or count_odd > odd_limit)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}