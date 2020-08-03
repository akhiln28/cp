#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <math.h>

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long double ans = 0, angle;
        for (int i = 0; i < n / 2; i++)
        {
            angle = M_PI * i / n;
            ans += 2 * sin(angle);
        }
        ans += 1;
        printf("%.10Lf\n", ans);
    }
    return 0;
}