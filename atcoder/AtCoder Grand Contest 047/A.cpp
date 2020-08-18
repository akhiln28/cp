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

#define max_n 1e9 + 7

long long arr[1000001];

long long fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return (n * fact(n - 1)) % 1000000007;
}

long long power(int n)
{
    if (n == 0) return 1;
    else if (!(n & 1))
    {
        long long ans = power(n/2);
        return (ans * ans) %  1000000007;
    }
    else 
    {
        long long ans = power(n/2);
        return (2 * ans * ans) %  1000000007;
    }
}

int main()
{
    int n; cin >> n;
    arr[0] = 1;
    for (size_t i = 1; i < 1000001; i++)
    {
        arr[i] = (i * arr[i - 1]) % 1000000007;
    }
    
    cout << arr[n] -  power(n - 1) << endl;
    return 0;
}