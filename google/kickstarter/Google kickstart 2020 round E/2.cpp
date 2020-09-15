#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, a, b, c; cin >> n >> a >> b >> c;
        if (n == 1)
        {
            if (a == 1 && b == 1 && c == 1) cout << "Case #" << t << ": 1" << endl;
            else cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        if (n == 2)
        {
            if (a == 2 && b == 1 && c == 1) cout << "Case #" << t << ": 1 2" << endl;
            else if (a == 1 && b == 2 && c == 1) cout << "Case #" << t << ": 2 1" << endl;
            else if (a == 2 && b == 2 && c == 2) cout << "Case #" << t << ": 1 1" << endl;
            else cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        if (a + b - c > n) cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        else
        {
            if (b - c == 0 && a - c != 0)
            {
                cout << "Case #" << t << ": ";
                for (int i = 0; i < a - c; i++) cout << "2 ";
                for (int i = 0; i < n - a - b + c; i++) cout << "1 ";
                for (int i = 0; i < c; i++) cout << "3 ";
            }
            else if (a - c == 0 && b - c != 0)
            {
                cout << "Case #" << t << ": ";
                for (int i = 0; i < c; i++) cout << "3 ";
                for (int i = 0; i < n - a - b + c; i++) cout << "1 ";
                for (int i = 0; i < b - c; i++) cout << "2 ";
            }
            else if (a - c == 0 && b - c == 0)
            {
                if (c == 1 && n != 1) cout << "Case #" << t << ": IMPOSSIBLE";
                else
                {
                    cout << "Case #" << t << ": ";   
                    cout << "3 ";
                    for (int i = 0; i < n - a - b + c; i++) cout << "1 ";
                    for (int i = 0; i < c - 1; i++) cout << "3 ";
                }
            }
            else
            {
                cout << "Case #" << t << ": ";
                for (int i = 0; i < a - c; i++) cout << "2 ";
                for (int i = 0; i < c; i++) cout << "3 ";
                for (int i = 0; i < n - a - b + c; i++) cout << "1 ";
                for (int i = 0; i < b - c; i++) cout << "2 ";
            }
            cout << endl;
        }
    }
}
