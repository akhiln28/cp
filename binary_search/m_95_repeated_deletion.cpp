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
    title: m_95_repeated_deletion.cpp
    author: Akhil
    date: 2021-03-20
    time: 09:30:34
    ==================================================
    abbbaac -> c
    aaabbbcccdd -> ''
    abcbb -> abc

    maintain the resulting string ans.
    we iterate over the string.
        if (ans.back() != current) ans.push_back(current);
        else
        {
            ch = ans.back(), ans.pop_back();
            iterate until current == ch;
        }
    return ans
*/

string solve(string str)
{
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        if (ans.back() != str[i]) ans.push_back(str[i]);
        else
        {
            char ch = ans.back();
            ans.pop_back();
            while (i < str.length() && str[i] == ch) i++;
            i--;
        }
    }
    return ans;
}

int main()
{
    string str = "aabbacc";
    auto ret = solve(str);
    cout << "answer: " << ret << endl;
    return 0;
}