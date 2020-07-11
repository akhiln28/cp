#include <iostream>
#include <algorithm>
#include <vector>
#define max_n 400

using namespace std;

int arr[max_n][max_n];

int m, n;
int num_neighbors(int **arr, int i, int j)
{
    int num_nz_neighbors = 0;
    if (i - 1 >= 0 && arr[i - 1][j])
    {
        num_nz_neighbors++;
    }
    if (j - 1 >= 0 && arr[i][j - 1])
    {
        num_nz_neighbors++;
    }
    if (i + 1 < n && arr[i + 1][j])
    {
        num_nz_neighbors++;
    }
    if (i - 1 >= 0 && arr[i - 1][j])
    {
        num_nz_neighbors++;
    }
    return num_nz_neighbors;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    return 0;
}