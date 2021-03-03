/*
    title: b.cpp
    author: Akhil
    date: 2020-11-15
    time: 08:42:20
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
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

long long myPow(long long x, long long p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  long long tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

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

int main()
{
    int T; cin >> T;
    for (int t2 = 1; t2 <= T; t2++)
    {
        string L, R; 
        cin >> L >> R; 
        vector<int> r(R.length()), l(R.length());
        for (int i = 0; i < (int) r.size(); i++)
        {
            r[i] = R[i] - '0';
        }
        for (int i = l.size() - 1; i >= (int) l.size() - (int) L.length(); i--)
        {
            l[i] = L[i - (int) l.size() + (int) L.length()] - '0';
        }
        
        int n = l.size();
        long long ans = 0; 
        for (int i = 0; i < n; i++)
        {
            if (l[i] < r[i])
            {
                long long t; 
                if ((i + 1) & 1)
                {
                    t = count_pos(l[i], r[i], true); 
                }
                else
                {
                    t = count_pos(l[i], r[i], false); 
                }
                if ((l[i] & 1) == ((i + 1) & 1))
                {
                    long long t1 = 1; 
                    for (int j = i + 1; j < n; j++)
                    {
                        t1 *= count_pos(l[j], 9, (j + 1) & 1);
                    }
                    ans += t1; 
                    t--;
                }
                if ((r[i] & 1) == ((i + 1) & 1))
                {
                    long long t1 = 1; 
                    for (int j = i + 1; j < n; j++)
                    {
                        t1 *= count_pos(0, r[j], (j + 1) & 1); 
                    }
                    t--;
                    ans += t1; 
                }
                ans += t * myPow(5, n - i - 1); 
                break;
            }
            else
            {
                int t = count_pos(l[i], r[i], (i + 1) & 1); 
                if (t == 0) break;
            }
        }
        cout << "Case #" << t2 << ": " << ans << endl;
    }
    return 0;
}
