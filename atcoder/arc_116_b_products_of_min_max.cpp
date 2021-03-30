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
    title: arc_116_b_products_of_min_max.cpp
    author: Akhil
    date: 2021-03-29
    time: 08:35:23
    ==================================================
    Given an array of integers A, find the sum of max(B) * min(B) for each subsequence/subset B of A.
    consider the example: 2 3 6
    here are the following subsets
    2 -> 2 * 2
    3 - 3 * 3
    6 - 6 * 6
    2 3 - 2 * 3
    2 6 - 2 * 6
    3 6 - 3 * 6
    2 3 6 - 2 * 6
    min(A) - 2 is will be present in 2^(n - 1) subsets
    max(A) - 6 also the same

    for each element need to calculate its contribution?
    since n <= 2 * 10^5, this should be solved in linear time.
    iterating through all the subsets (2^n) is not feasible.

*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
    }
    return 0;
}