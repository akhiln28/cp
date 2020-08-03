#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <string>

#define max_n 52

using namespace std;
vector<string> strings;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        strings.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> strings[i];
        }
        bool flag = true;
        string ans = " ";
        map<char, int> mp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[strings[j][0]]++;
            }
            if (mp.size() <= 2)
            {
                cout << "test" << endl;
                auto it = mp.begin();
                if (it->second == 1)
                {
                    cout << "test2" << endl;
                    ans += (++it)->first;
                }
                else if((++it)->second == 1)
                {
                    cout << "test1" << endl;     
                    auto it = mp.begin();
                    ans += it->first;
                }
                else flag = false;
            }
            else flag = false;
            if (!flag)
                break;
        }
        if (!flag)
            cout << "-1" << endl;
        else cout << ans << endl;
    }

    return 0;
}
