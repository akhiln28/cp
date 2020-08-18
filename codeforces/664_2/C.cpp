#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    set<int> s; s.insert(0);
    for (int i = 0; i < n; i++)
    {
        set<int> s1;
        for (auto e : s)
        {
            for (int j = 0; j < m; j++)
            {
                s1.insert(e | (a[i] & b[j]));
            } 
        }
        s.clear(); s = s1;
    }
    cout << *s.begin() << endl;
}