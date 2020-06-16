#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <string>

#define max_n 52

using namespace std;

int arr[max_n][max_n];
bool valid[max_n][max_n];

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
        bool flag = true;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                valid[i][j] = false;
                if (arr[i][j] == 1)
                {
                    if (i == n - 1 || j == n - 1)
                    {
                        valid[i][j] = true;
                    }
                    else
                    {
                        if (i + 1 <= n - 1 && valid[i + 1][j])
                            valid[i][j] = true;
                        if (j + 1 <= n - 1 && valid[i][j + 1])
                            valid[i][j] = true;
                    }
                    if (!valid[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
