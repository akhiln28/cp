---
Created Time: Feb 10, 2021 11:53 PM
Do Date: Feb 28, 2021
Last edited time: Feb 28, 2021 8:37 AM
Points: 1500
Status: done
Tags: own
---

# Number of ways to pick first or last

You are given an array of integers of length n. In each step you can pick either the first element or the last element. Find the number of permutations possible? Also print all the permutations.
---
Answer will be $2 ^ {n - 1}$
```cpp
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
void print_permutations(int i, int j, vector<int>& ans, vector<int>& nums)
{
    if (i == j)
    {
        ans.push_back(nums[i]); 
        for (int k = 0; k < ans.size(); k++) cout << ans[k] << " "; cout << endl;
        ans.pop_back();
        return;
    }
    else
    {
        ans.push_back(nums[i]); 
        print_permutations(i + 1, j, ans, nums); 
        ans.pop_back();
        ans.push_back(nums[j]); 
        print_permutations(i, j - 1, ans, nums);
        ans.pop_back();
    }
}
int main()
{
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        v[i] = i; 
    }
    vector<int> ans; 
    print_permutations(0, n - 1, ans, v); 
    return 0;
}
```
Patterns: [Backtracking](Backtracking.md)