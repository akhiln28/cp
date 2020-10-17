#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#define max_n 100001
using namespace std;


int arr[max_n];
/*
Question: Given an array, find the longest sub array such that sum of elements in the subarry is not
divisible by given x;

 */
int main() {
    int t, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for (int i = 0; i < n;i++)
        {
            cin >> arr[i];
        }
        // brute force O(n^2) - doesn't work

        // answer is simple, either n - 1 or n when all the numbers are greater than 0
        int ans = 0;
        long long sum = (long long) accumulate(arr, arr + n, 0);
        if (sum % x != 0) cout << n << endl;
        else 
        {
            int lzeroes = 0, rzeroes = 0;
            for (int i = 0;i < n;i++)
            {
                if (arr[i] % x == 0) lzeroes++;
                else break;
            }
            for (int i = n - 1;i >= 0;i--)
            {
                if (arr[i] % x == 0) rzeroes++;
                else break;
            }
            ans = max(n - lzeroes - 1, n - rzeroes - 1);
            if (ans <= 0) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}