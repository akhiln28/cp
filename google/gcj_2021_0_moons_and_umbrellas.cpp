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
    title: gcj_2021_0_moons_and_umbrellas.cpp
    author: Akhil
    date: 2021-03-30
    time: 08:05:12
    ==================================================
    Given a string containing C, J and ?. CJ - cost x, JC cost = y
    CJ?CC? -> CJCCCC ans = x + y
    CJCJ -> x + y + x
    C?J ->
    will the greedy solution work?
    processing a question mark...
    few cases to consider
    C??J - #? = count, four cases min(x, y, )
        CJCJ -> 2*x
        CJJC -> x + y
        C?????J ->
    J??C - easy
    J??J
    C??C
    C???
    ???C
    J???
    ???J
    both x > 0 and y > 0
        if x < y
            C??J -> CJJJ
            C???J ->
*/
int solve(int x, int y, string &s)
{

}
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int x, y; cin >> x >> y;
        string s; cin >> s;
    }
    return 0;
}