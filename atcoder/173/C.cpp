#include <iostream>

using namespace std;

char arr[7][7];
int H, W, K;

int recursive_solve(int i, int j, int k)
{
    if ((i >= H || j >= W) || k <= 0) return 0;
    
    int cnt_r = 0, cnt_c = 0;
    for (int b = 0; b < W; b++)
    {
        if (arr[i][b] == '#') cnt_r++;
    }
    for (int a = 0; a < H; a++)
    {
        if (arr[a][j] == '#') cnt_c++;
    }
    return recursive_solve(i + 1, j, k) +
            recursive_solve(i, j + 1, k) +
            recursive_solve(i + 1, j + 1, k) + 
            recursive_solve(i + 1, j, k - cnt_r) + 
            recursive_solve(i, j + 1, k - cnt_c) + 
            recursive_solve(i + 1, j + 1, k - cnt_r - cnt_c);
}

int main()
{
    cin >> H >> W >> K;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << recursive_solve(0, 0, K) << endl;
}