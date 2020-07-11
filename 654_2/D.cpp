#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <utility>

#define max_n 301
using namespace std;

int arr[max_n][max_n];

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
        }

        int i = 0, j = 0;
        for (int l = 0; l < k; l++)
        {
            arr[i][j] = 1;
            i++;
            j = (j + 1) % n;
            if (i == n)
            {
                i = 0;
                j = (j + 1) % n;
            }
        }
        if (k % n == 0)
            cout << 0 << endl;
        else
            cout << 2 << endl;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}