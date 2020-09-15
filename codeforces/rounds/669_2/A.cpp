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
        int n;
        cin >> n;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x)
                c2++;
            else
                c1++;
        }
        if (n % 4 == 0)
        {
            int x;
            if (c1 >= c2) x = 0;
            else x = 1;
            cout << n/2 << endl;
            for (int i = 0; i < n/2; i++)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            int x, k;
            if (c1 >= c2) x = 0, k = n/2; 
            else x = 1, k = n/2 + 1;
            cout << k << endl;
            for (int i = 0; i < k; i++)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}