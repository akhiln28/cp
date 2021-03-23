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
    title: kickstart_2020_g.cpp
    author: Akhil
    date: 2021-03-21
    time: 07:46:53
    ==================================================
    Find the number of lucky fragments. (that start at KICK and end at START)
    k s k s -> 3 done
    s k -> 0 done
    k k s k s -> 2 + 2 + 1 = 5 done
    k k k k k s s s s -> 20 done
    need to think about all the corner test cases
    s s s s -> 0
    k k k k -> 0
    s s s s k -> 0
    k s k s k s k s -> 4 + 3 + 2 + 1 = 10
    I found the mistake in my algorithm. Consider KICKICKICK...
    You should not do i += 3, it should be i += 2;
*/
int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        string str; cin >> str;
        string ks;
        int i = 0;
        while (i < str.length())
        {
            if (i + 3 < str.length() and str.substr(i, 4) == "KICK") ks.push_back('0'), i += 2;
            else if (i + 4 < str.length() and str.substr(i, 5) == "START") ks.push_back('1'), i += 4;
            i++;
        }
        // suffix sum containing the count of '1' to the right
        vector<int> suff(ks.size());
        if (suff.size()) suff[suff.size() - 1] = (ks.back() == '1');
        for (int i = suff.size() - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + (ks[i] == '1');
        }
        long long ans = 0;
        for (int i = 0; i < ks.size(); i++)
        {
            if (ks[i] == '0') ans += suff[i];
        }
        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}