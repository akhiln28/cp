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
    title: kickstart_2021A_1.cpp
    author: Akhil
    date: 2021-03-21
    time: 09:30:03
    ==================================================
    ABCAA -> score = 1
    ABAA -> score = 1
*/
int main()
{
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int score = 0;
        for (int i = 0; i < n / 2; i++)
        {
            score += (str[i] != str[n - i - 1]);
        }
        cout << "Case #" << case_num << ": " << abs(k - score) << endl;
    }
    return 0;
}