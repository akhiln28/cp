#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

#define max_n 10000

int power2(int n)
{
    if (n == 0) return 1; 
    int ans = 0; 
    while (n % 2 == 0) ans++, n /= 2; 
    return ans; 
}
int power5(int n)
{
    if (n == 0) return 1; 
    int ans = 0; 
    while (n % 5 == 0) ans++, n /= 5; 
    return ans; 
}

int main()
{
    int n; cin >> n; 
    vector<vector<int>> mat(n, vector<int> (n));
    bool contains_zero = false; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (!mat[i][j]) contains_zero = true; 
        }
    }

    vector<vector<int>> dp1(n, vector<int> (n, max_n));
    vector<vector<int>> dp2(n, vector<int> (n, max_n));

    dp1[n - 1][n - 1] = power2(mat[n - 1][n - 1]); 
    dp2[n - 1][n - 1] = power5(mat[n - 1][n - 1]); 

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i + 1 < n) dp1[i][j] = dp1[i + 1][j] + power2(mat[i][j]);
            if (j + 1 < n) dp1[i][j] = min(dp1[i][j], dp1[i][j + 1] + power2(mat[i][j])); 

            if (i + 1 < n) dp2[i][j] = dp2[i + 1][j] + power5(mat[i][j]);
            if (j + 1 < n) dp2[i][j] = min(dp2[i][j], dp2[i][j + 1] + power5(mat[i][j])); 
        }
    }

    int ans = min(dp1[0][0], dp2[0][0]); 
    if (contains_zero) ans = min(1, ans); 
    cout << ans << endl;
    if (ans == dp1[0][0])
    {
        int i = 0, j = 0; 
        while (i < n && j < n)
        {
            int right = (j + 1 < n) ? dp1[i][j + 1] : max_n;
            int down = (i + 1 < n) ? dp1[i + 1][j] : max_n;
            if (right < down) 
            {
                cout << 'R';
                j++; 
            }
            else
            {
                if (down != max_n) cout << 'D';
                i++;
            }
        }
        cout << endl;
    }   
    else
    {
        int i = 0, j = 0; 
        while (i < n && j < n)
        {
            int right = (j + 1 < n) ? dp2[i][j + 1] : max_n;
            int down = (i + 1 < n) ? dp2[i + 1][j] : max_n;
            if (right < down) 
            {
                cout << 'R';
                j++; 
            }
            else
            {
                if (down != max_n) cout << 'D';
                i++;
            }
        }
        cout << endl;
    } 
    return 0;
}