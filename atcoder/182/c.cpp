/*
    title: c.cpp
    author: Akhil
    date: 2020-11-08
    time: 17:38:10
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
    long long n; cin >> n;
    if (n % 3 == 0) 
    {
        cout << 0 << endl;
        return 0; 
    }
    vector<int> digits; 
    long long temp = n; 
    while (temp)
    {
        digits.push_back(temp % 10); 
        temp /= 10; 
    }
    int rem[3] = {0, 0, 0}; 
    for (auto d : digits)
    {
        if (d % 3 == 0) rem[0]++;
        else if (d % 3 == 1) rem[1]++;
        else rem[2]++;
    }
    if (rem[n % 3] && digits.size() > 1) 
    {
        cout << 1 << endl;
        return 0; 
    }
    else if (n % 3 == 1 && rem[2] >= 2 && digits.size() > 2)
    {
        cout << 2 << endl;
        return 0; 
    }
    else if (n % 3 == 2 && rem[1] >= 2 && digits.size() > 2)
    {
        cout << 2 << endl;
        return 0; 
    }
    cout << -1 << endl;
    return 0;
}

