#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int t;
    long long n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long LCD = INT_MAX;
        long long a;
        for (long long i = 1; i <= (long long)ceil(sqrt(n)); i++)
        {
            if (n % i == 0 && n - i > 0)
            {
                long long lcd = i * (n - i) / __gcd(i, n - i);
                if (LCD >= lcd)
                {
                    a = i;
                    LCD = lcd;
                }
                long long i1 = n / i;
                if (i1 > 0 && n - i1 > 0)
                {
                    lcd = i1 * (n - i1) / __gcd(i1, n - i1);
                    if (LCD >= lcd)
                    {
                        a = i1;
                        LCD = lcd;
                    }
                }
                // cout << i << " " << LCD << endl;
            }
        }
        cout << a << " " << n - a << endl;
    }
    return 0;
}