#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <numeric> 
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int n; cin >> n;
    long long ans = 0; 
    for (int i = 1; i <= n; i++)
    {
        long long count = n/i;
        ans += i * (count * (count + 1))/2;
    }
    cout << ans << endl;
    return 0; 
}