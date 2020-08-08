#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    unordered_map<long long, int> mpa,mpb;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        mpa[a[i]] = i;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> b[i];
        mpb[b[i]] = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (size_t i = 0; i < m; i++)
    {
        cout << mpa[a[0]] << " " << mpb[b[i]] << endl;
    }
    for (size_t i = 1; i < n; i++)
    {
        cout << mpa[a[i]] << " " << mpb[b[m - 1]] << endl;
    }
    return 0;
}