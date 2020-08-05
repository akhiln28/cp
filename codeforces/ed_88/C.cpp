#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <string>
#include <map>

#define max_n 1001
using namespace std;

double arr[max_n];
int main()
{
    int t, h, c, T;
    cin >> t;
    while (t--)
    {
        cin >> h >> c >> T;
        double diff = (double)INT16_MAX;
        long long sum = 0;
        for (int i = 0; i < max_n; i++)
        {
            if (i & 1)
                sum += c;
            else
                sum += h;
            arr[i] = abs((double)T - (double)sum / (i + 1));
            diff = min(diff, arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < max_n; i++)
        {
            if (diff == arr[i]) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}