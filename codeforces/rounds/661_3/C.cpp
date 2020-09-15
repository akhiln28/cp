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
        vector<int> w(n);
        map<int, int> mp;
        for (size_t i = 0; i < n; i++)
        {
            cin >> w[i];
            mp[w[i]]++;
        }
        int max_teams = 0;
        for (size_t i = 2; i <= 2*n; i++)
        {
            int count = 0;
            auto temp = mp;
            for (size_t j = 0; j < n; j++)
            {
                if (temp[i - w[j]] > 0)
                {
                    count++;
                    temp[i - w[j]]--;
                }
            }
            count /= 2;
            max_teams = max(max_teams, count);
        }
        cout << max_teams << endl;
    }

    return 0;
}