#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int i = 0;
        while (v[i] == 1)
        {
            i++;
        }
        if (i < n)
        {
            if (i & 1)
            {
                cout << "Second" << endl;
            }
            else
                cout << "First" << endl;
        }
        else
        {
            if (n & 1)
            {
                cout << "First" << endl;
            }
            else
                cout << "Second" << endl;
        }
    }

    return 0;
}