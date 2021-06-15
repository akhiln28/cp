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
    title: abc200_2.cpp
    author: Akhil
    date: 2021-05-08
    time: 17:31:30
    ==================================================
*/
int main()
{
    long long n, k; cin >> n >> k;
    while (k--)
    {
        if (n % 200 == 0) n = n / 200;
        else n = stoll(to_string(n) + "200");
    }
    cout << n << endl;
    return 0;
}