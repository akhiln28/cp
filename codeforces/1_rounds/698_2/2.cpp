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

bool is_possible(int d, long long n)
{
    long long start = d, factor = 1; 
    while (start * factor <= n)
    {
        long long cur = n - n % factor;
        for (int i = 0; i < 9; i++)
        {
            cur -= start * factor; 
            if (cur >= 0 && cur % (10 * factor) == 0) 
            {
                return true; 
            }
            else if (cur < 0) break; 
        }
        factor *= 10; 
    }
    return false; 
}

int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n, d; cin >> n >> d; 
        vector<long long> v(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i]; 
            cout << ((is_possible(d, v[i])) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}