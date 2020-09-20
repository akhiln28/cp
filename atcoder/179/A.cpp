/*
    title: A.cpp
    author: Akhil
    date: 2020-09-19
    time: 17:29:37
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    string s; cin >> s;
    if (s[s.length() - 1] == 's') s = s + "es";
    else s = s + 's'; 
    cout << s << endl;
    return 0;
}