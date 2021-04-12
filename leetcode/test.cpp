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
    title: test.cpp
    author: Akhil
    date: 2021-03-28
    time: 08:40:39
    ==================================================
    We can do binary search on the mountain.
    But the value we need to compare is very large. Which cannot be stored in long long.
    We need to find the optimal split size without doing the binary search.
*/

int product(int splits, int n)
{
    vector<int> vals(splits, n/splits);
    for (int i = 0; i < n % splits; i++) vals[i]++;
    long long ans = 1;
    for (int i = 0; i < vals.size(); i++)
    {
        ans *= vals[i];
    }
    return ans;
}
// will tokenise the words (will contain spaces or special characters in between the words)
vector<string> tokenise(string &str)
{
    vector<string> ans;
    string cur = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ('a' <= str[i] and str[i] <= 'z') cur += str[i];
        else if (cur.size())
        {
            ans.push_back(cur);
            cur = "";
        }
    }
    if (cur.size()) ans.push_back(cur);
    return ans;
}
int main()
{
    vector<int> v{2, 3, 239};
    v.push_back({2, 43});
    return 0;
}