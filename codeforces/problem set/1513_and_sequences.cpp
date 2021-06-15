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
    title: 1513_and_sequences.cpp
    author: Akhil
    date: 2021-04-16
    time: 07:47:22
    ==================================================
    a1, a2, a3,... , an
    a1 = a2&a3&...&an
        an = a1&a2&...an-1
    => a1 = a1&a2&a3&...&an-1 = an
    => a1 = a1&a3&...&an
    a1&a2 = a3&...&an
    => a1&a2 = a1&a2&a3
    => a1&a2 = a2&a3&...&an = an = a1
    => a1&a2&a3&a4 = a2&a3&a4&...&an = a1 = an
    => a1 and an should be equal and all others x, should be a1 & x = a1
    1 1 3 5

*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
    }
    return 0;
}