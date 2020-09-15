#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x, t; cin >> n >> x >> t;
    cout << (int)ceil((float)n/x) * t << endl;
    return 0;
}