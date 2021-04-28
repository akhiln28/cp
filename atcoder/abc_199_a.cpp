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
    title: abc_199_a.cpp
    author: Akhil
    date: 2021-04-24
    time: 17:42:04
    ==================================================
*/
int main()
{

    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a * a + b * b < c * c) ? "Yes" : "No") << endl;
    return 0;
}