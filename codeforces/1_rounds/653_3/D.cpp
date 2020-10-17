#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin >> t;
    long long k, n;
    while(t--)
    {
        cin >> n >> k;
        map<long long, long long> arr;
        long long x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr[k - x % k]++;
        }
        long long max_ans = 0, max_k = 0;
        for (auto it : arr)
        {
            // cout << it.first << "," << it.second << " ";
            if (it.first == k)
                continue;
            if (max_ans <= it.second)
            {
                max_ans = it.second;
                max_k = it.first;
            }            
        }
        // cout << endl;
        // cout << max_ans << " " << max_k << endl;
        if (max_ans >= 1)
            cout << (max_ans - 1) * k +  max_k + 1 << endl;
        else cout << '0' << endl;
    }
    return 0;

}

