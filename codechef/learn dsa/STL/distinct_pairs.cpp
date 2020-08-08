#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    map<long long, int> mp;
    int count = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (count == n + m - 1)
                break;
            int sum = a[i] + b[j];
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = 1;
                cout << i << " " << j << endl;
                count++;
            }
        }
        if (count == n + m - 1) break;
    }
    return 0;
}