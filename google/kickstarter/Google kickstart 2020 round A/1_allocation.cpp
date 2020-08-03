#include <iostream>
#include <algorithm>

#define max_n 100001

using namespace std;

int arr[max_n];

int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ans = 0, i = 0;
        while (k > 0 && i < n)
        {
            k -= arr[i];
            if (k >= 0)
                ans++;
            i++;
        }
        cout << "case #" << l << ": " << ans << endl;
    }
    return 0;
}