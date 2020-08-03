#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <string>

#define max_n 52

using namespace std;

int arr[max_n][max_n];
int row_cum[max_n][max_n];
int col_cum[max_n][max_n];

int main()
{
    int t, n;
    char ch;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ch;
                arr[i][j] = (ch == '1') ? 1 : 0;
            }
        }
        // row cum
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                row_cum[i][j] = row_cum[i][j - 1] + arr[i][j];
            }
        }
        // col cum
        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < n; i++)
            {
                col_cum[i][j] = col_cum[i - 1][j] + arr[i][j];
            }
        }
        bool row_flag = false, col_flag = false, flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j])
                {
                    row_flag = row_cum[i][n - 1] - row_cum[i][j] == n - 1 - j;
                    col_flag = col_cum[n - 1][j] - col_cum[i][j] == n - 1 - i;
                    flag = row_flag || col_flag;
                    if (!flag)
                        break;
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}
