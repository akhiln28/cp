#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
    int n; cin >> n;
    long long x; 
    long long sum = 0, big = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x, big = max(big, x);
    }
    cout << ((sum % 2 == 0 && big <= sum/2) ? "YES" : "NO") << endl;
}