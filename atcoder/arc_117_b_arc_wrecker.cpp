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
    title: arc_117_b_arc_wrecker.cpp
    author: Akhil
    date: 2021-04-22
    time: 07:42:53
    ==================================================
    Given a list of positive integers a1, a2, .., an
    In one operation you can choose one integer x, and reduce all the positive integers >= x by one
    Need to find the number of possible scenarios of buildings?
    Examples:
    (1, 2) => (0, 0), (0, 1), (1, 1), (1, 2)
    (1, n) => (0, {0 to n - 1}), (1, {1 to n}) => total = n + n = 2n
    (2, 5, 10) => (2, 5, {5 to 10}), in this case a3 >= a2 >= a1, no matter the values this condition should hold.
    we can sort the values as well and say each scenario should satisfy => a1 <= a2 <= a3 <= ... <= an, (say initial values A1, A2, .., An)
    I feel like I have seen this before, but can't quite get to the solution.
    (2, 5, 10) => 121 =>
    (2, 3, 4) => (14 + 9 + 5) =>
    The only thing I can think of is solving by DP. dp[i] => count upto i
    dp[i + 1] = s
    consider a0, let the number of possibilities of the remaining a1 to an is x.
    This is part of permutations and combinations
*/
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    return 0;
}