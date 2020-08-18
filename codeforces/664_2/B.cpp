#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main() 
{
    int n, m, x, y; cin >> n >> m >> x >> y;
    bool arr[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            arr[i][j] = false;
        }
    }
    cout << x << " " << y << endl; arr[x][y] = true;
    cout << 1 << " " << y << endl; arr[1][y] = true;
    int count = 2;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!arr[i][j])
                    cout << i << " " << j << endl;
            }
        }
        else
        {
            for (int j = m; j >= 1; j--)
            {
                if (!arr[i][j])
                    cout << i << " " << j << endl;
            }
        }  
    }
}