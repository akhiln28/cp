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

int main()
{
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n; cin >> n; 
        vector<long long> v(2 * n); 
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> v[i]; 
        }
        sort(v.begin(), v.end()); 
        bool flag = true; 
        vector<long long> d; 
        for (int i = 1; i < 2 * n; i += 2)
        {
            if (v[i] != v[i - 1] || v[i] % 2 != 0)
            {
                flag = false;
                break;
            }
            d.push_back(v[i]); 
        }
        
        if (flag)
        {
            long long sum_diff = 0, cum_diff = 0; 
            for (int i = 1; i < d.size(); i++)
            {
                long long diff = d[i] - d[i - 1]; 
                cum_diff += diff / (2 * i); 
                sum_diff += cum_diff;
                if (!(diff > 0 && diff % (2 * i) == 0))
                {
                    flag = false;
                    break;
                }
            }
            if (!((d[0]/2 - sum_diff) % n == 0 && (d[0]/2 - sum_diff) > 0)) 
            {
                flag = false; 
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}