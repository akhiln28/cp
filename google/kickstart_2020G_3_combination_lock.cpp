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
    title: kickstart_2020G_3_combination_lock.cpp
    author: Akhil
    date: 2021-03-21
    time: 08:46:47
    ==================================================
    Given an array of integers between 1 and N
    operation is as follows X -> (X + 1) % N or (X - 1) % N
    #minimum number of operations to make all of them equal
    N = 5
    2 3 4 -> 1 + 0 + 1 = 2
    If we know the final value that all numbers need to be converted, then O(n)
    N = 10
    2 9 3 8
    final value
    2 -> 0 +
    After testing for sample case, I am assuming that this is a binary search question.
*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n, N;
        cin >> n >> N;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        auto dist = [&](int a, int b){
            // dist(2, 9) -> min(7, abs(2 - (-1)))
            return min(abs(a - b), abs(N + a - b));
        };
        auto value = [&](int mid){
            long long ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += dist(mid, nums[i]);
            }
            return ans;
        };
        for (int i = 1; i <= N; i++)
        {
            int ans = 0;
            for (int j = 0; j < n; j++)
            {
                ans += dist(i, nums[j]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}