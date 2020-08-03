#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <map>

#define max_n 101
#define max_m 1001
using namespace std;

char arr[max_n][max_m];

int main()
{
    int t, n, m, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x >> y;
        int countdot = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '.')
                    countdot++;
            }
        }
        if (x <= y / 2)
        {
            cout << countdot * x << endl;
        }
        else
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int t1 = 0;
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == '.')
                        t1++;
                    else
                    {
                        ans += (t1 / 2) * y + (t1 & 1) * x;
                        t1 = 0;
                    }
                }
                ans += (t1 / 2) * y + (t1 & 1) * x;
                t1 = 0;
            }
            cout << ans << endl;
        }
    }

    return 0;
}