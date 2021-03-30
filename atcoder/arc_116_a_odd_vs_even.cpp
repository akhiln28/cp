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
    title: arc_116_a_odd_vs_even.cpp
    author: Akhil
    date: 2021-03-29
    time: 08:30:02
    ==================================================
    Given a positive integer check if there are more odd divisors or even?
    Prime factorization required?
    Need to check prime_factors(N with 2 factors removed) > prime_factors(N with only one 2 factor removed)
*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        long long N; cin >> N;
        int power2 = 0;
        while (N % 2 == 0) power2++, N /= 2;
        if (power2 == 1) cout << "Same" << endl;
        else if (power2 == 0) cout << "Odd" << endl;
        else cout << "Even" << endl;
    }
    return 0;
}