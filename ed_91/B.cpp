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
    for (size_t t = 0; t < T; t++)
    {
        string str;
        cin >> str;
        int r = 0, p = 0, s = 0;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == 'R')
                r++;
            else if (str[i] == 'P')
                p++;
            else if (str[i] == 'S')
                s++;
        }
        string c;
        if (r >= max(p, s))
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                c += 'P';
            }
        }
        else if (p >= max(s, r))
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                c += 'S';
            }
        }
        else if (s >= max(r, p))
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                c += 'R';
            }
        }
        else
            c = str;
        cout << c << endl;
    }
    return 0;
}