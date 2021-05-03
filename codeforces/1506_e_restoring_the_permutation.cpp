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
    title: 1506_e_restoring_the_permutation.cpp
    author: Akhil
    date: 2021-05-03
    time: 09:14:14
    ==================================================
    You have a permutation qn such that qi = max(p1, p2, .., pi) where pn is also a permutation of size n.
    Find the lexicographically least and maximum permutation p possible?
    examples:
    q - [3, 3, 4, 4, 7, 7, 7]
    p_min = [3, 1, 4, 2, 7, 5, 6]
    p_max = [3, 2, 4, 1, 7, 6, 5]
    I think logic is kind of easy.

    init set s1 = seq(1 to n)
    init set s2 = seq(1 to n)
    for i in range(q.len):
        if (q[i] > q[i - 1]):
            p1[i] = q[i]
            p2[i] = q[i]
            remove p1[i] from s1
            remove p2[i] from s2
        else:
            p1[i] = minimum element in s1
            p2[i] = maximum element less than q[i]
            remove p1[i] from s1
            remove p2[i] from s2
*/

void solve()
{
    int n; cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    vector<int> p1(n), p2(n);
    set<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        s1.insert(i + 1);
        s2.insert(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0 or q[i] > q[i - 1])
        {
            p1[i] = q[i];
            p2[i] = q[i];
        }
        else
        {
            p1[i] = *s1.begin();
            auto it2 = s2.upper_bound(q[i]);
            p2[i] = *(--it2);
        }
        s1.erase(p1[i]);
        s2.erase(p2[i]);
    }
    for (int i = 0; i < n; i++) cout << p1[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) cout << p2[i] << " "; cout << endl;
}

int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        solve();
    }
    return 0;
}