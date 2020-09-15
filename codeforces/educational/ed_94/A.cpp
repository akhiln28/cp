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
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (!(i & 1)) cout << s[i]; 
        }
        cout << endl;
    }
    return 0;
}