#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

// pending

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int a, b; cin >> a >> b;
        cout << (int) ceil(abs(a - b)/10.0) << endl;
    }
}