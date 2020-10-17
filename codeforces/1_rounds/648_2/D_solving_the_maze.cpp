#include <iostream>
#include <climits>
#include <string>
#include <queue>
#include <utility>
#define max_n 51
using namespace std;

char arr[max_n][max_n];
bool debug = false;
int main() 
{
    int t, m, n;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int good_count = 0;
        for (int i = 0; i< n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'G')
                    good_count++;
            }
        }
        string ans = "YES";
        // blocking all the neighbours of B
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                if (arr[i][j] == 'B')
                {
                    // traversing the neighbours
                    if (i + 1 <= n - 1)
                    {
                        if (arr[i + 1][j] == 'G') ans = "NO1";
                        else arr[i + 1][j] = '#';
                    } 
                    if (i - 1 >= 0)
                    {
                        if (arr[i - 1][j] == 'G') ans = "NO2";
                        else arr[i - 1][j] = '#';
                    } 
                    if (j + 1 <= m - 1)
                    {
                        if (arr[i][j + 1] == 'G') ans = "NO3";
                        else arr[i][j + 1] = '#';
                    }
                    if (j - 1 >= 0)
                    {
                        if (arr[i][j - 1] == 'G') ans = "NO4";
                        else arr[i][j - 1] = '#';
                    }

                }
            }
        }
        // debug
        for (int i = 0; i < n ;i ++)
        {
            for (int j = 0; j < m; j++)
            {
                if (debug)
                cout << arr[i][j] << ' ';
            }
            if (debug) cout << endl;
        }
        if (ans != "YES" || arr[n - 1][m - 1] == '#') 
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            int bfs_goods = 0;
            // checking if every good is connected to n, m cell.
            // bfs from nxm would suffice
            queue<pair<int, int>> que;
            que.push(make_pair(n - 1,m - 1));

            while(!que.empty())
            {
                pair<int, int> p = que.front(); que.pop();
                if (arr[p.first][p.second] == 'G')
                    bfs_goods++;
                if (p.second - 1 >= 0 && arr[p.first][p.second - 1] != '#')
                {
                    que.push(make_pair(p.first, p.second - 1));
                }
                if (p.first - 1 >= 0 && arr[p.first - 1][p.second] != '#')
                {
                    que.push(make_pair(p.first - 1, p.second));
                }
            }
            if (bfs_goods != good_count) {
                if (debug)
                {
                    cout << bfs_goods << ' ' << good_count << endl;
                }
                cout << "NO" << endl;
            }
            else 
            {
                if (debug)
                {
                    cout << bfs_goods << ' ' << good_count << endl;
                }

                cout << "YES" << endl;
            }
        }
    }
    return 0;
}