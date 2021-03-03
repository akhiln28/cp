/*
    title: b1.cpp
    author: Akhil
    date: 2020-11-15
    time: 09:52:24
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int count_pos(int left, int right, bool odd)
{
    if (odd) 
    {
        return (right - left + (left & 1) + 1)/2; 
    }
    else
    {
        return (right - left + (left % 2 == 0) + 1)/2;     
    }
}

long long myPow(long long x, long long p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  long long tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

long long recur(string s, bool odd)
{
    if (s.length() == 0) return 1; 
    return (count_pos(0, s[0] - '0', odd) - ((s[0] & 1) == odd)) * myPow(5, s.length() - 1) + ((s[0] & 1) == odd) * recur(s.substr(1), !odd);
}

bool is_boring(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (((i + 1) & 1) != ((s[i] - '0') & 1)) return false;
    }
    return true;
}

long long solve(string s)
{
    long long ans = 0; 
    for (int i = 1; i < s.length(); i++)
    {
        ans += myPow(5, i);
    }
    ans += recur(s, true); 
    return ans;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string l, r; 
        cin >> l >> r;
        cout << "Case #" << t << ": " << solve(r) - solve(l) + is_boring(l) << endl;
    }
    return 0;
}
