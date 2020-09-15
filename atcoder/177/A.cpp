#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;


int main()
{
    int d, t, s; cin >> d >> t >> s;
    cout << (((float) d / s <= t) ? "Yes" : "No") << endl;
    return 0;
}