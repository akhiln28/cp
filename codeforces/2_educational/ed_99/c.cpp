/*
    title: c.cpp
    author: Akhil
    date: 2020-11-30
    time: 20:26:23
*/

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

int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int x, y; cin >> x >> y; 
        cout << x - 1 << " " << y << endl;
    }
    return 0;
}
