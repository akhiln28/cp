#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <string>
#include <map>

#define max_n 100001
using namespace std;

int arr[max_n];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0, maxe = INT16_MIN, ans1 = INT16_MIN, ans2 = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        maxe = max(maxe, arr[i]);
        sum += arr[i];
        ans1 = max(sum - maxe, ans1);
        if (sum < 0)
        {
            sum = 0;
            maxe = INT16_MIN;
        }
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxe = max(maxe, arr[i]);
        sum += arr[i];
        ans2 = max(sum - maxe, ans2);
        if (sum - maxe < 0)
        {
            sum = 0;
            maxe = INT16_MIN;
        }
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}