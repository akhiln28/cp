#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <stdlib.h>

#define max_n 100001

using namespace std;

void generate_subsequence(vector<int> &ans, list<pair<char, int>> &lt, int set_count)
{
    auto it = lt.begin();
    bool flag = (it->first == '1');
    ans[it->second] = set_count;
    lt.erase(it++);
    while (it != lt.end())
    {
        if (flag != (it->first == '1'))
        {
            ans[it->second] = set_count;
            lt.erase(it++);
            flag = !flag;
        }
        else it++;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        char ch;
        list<pair<char, int> > lt;
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> ch;
            lt.push_back(make_pair(ch, i));
        }

        int set_count = 1;
        while (!lt.empty())
        {
            generate_subsequence(ans, lt, set_count);
            set_count++;
        }
        cout << set_count - 1 << endl;
        for (size_t i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }cout << endl;

    }

    return 0;
}