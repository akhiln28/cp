#include <bits/stdc++.h>

using namespace std;

#define maxn 101

long double dp[maxn][maxn][maxn];

long double expectation(int a, int b, int c)
{
    if (a == 100 or b == 100 or c == 100) return 0; 
    if (dp[a][b][c]) return dp[a][b][c];
    dp[a][b][c] = (a * (1 + expectation(a + 1, b, c)) + b * (1 + expectation(a, b + 1, c)) + c * (1 + expectation(a, b, c + 1)))/(long double)(a + b + c); 
    return dp[a][b][c];
}
int main()
{
    int a, b, c; cin >> a >> b >> c;
    memset(dp, 0, maxn * maxn * maxn * sizeof(long double));
    cout << setprecision(10) << expectation(a, b, c) << endl;
    return 0; 
}