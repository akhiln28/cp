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

// check if n can be expressed as the distinct powers of three
// convert the number into base 3 format (all digits should be less than or equal to 1)
bool checkPowersOfThree(int n)
{
    while (n)
    {
        int rem = n % 3;
        if (rem > 1) return false;
        n /= 3;
    }
    return true;
}

int main()
{
    int n; cin >> n;
    cout << (checkPowersOfThree(n) ? "true": "false") << endl;
    return 0;
}