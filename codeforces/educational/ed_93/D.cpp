#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int rect_area(set<int> &s1, set<int> &s2, set<int> &s3)
{
    int a = (!s1.empty()) ? *s1.rbegin() : -1;
    int b = (!s2.empty()) ? *s2.rbegin() : -1;
    int c = (!s3.empty()) ? *s3.rbegin() : -1;

    if (a <= min(b, c))
    {
        s2.erase(b);
        s3.erase(c);
        return b * c;
    }
    if (b <= min(a, c))
    {
        s1.erase(a);
        s3.erase(c);
        return a * c;
    }
    if (c <= min(a, b))
    {
        s1.erase(a);
        s2.erase(b);
        return a * b;
    }
    return 0;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    set<int> r, g, b;
    int x;
    for (int i = 0; i < n1; i++)
    {
        cin >> x, r.insert(x);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> x, g.insert(x);
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> x, b.insert(x);
    }
    long long ans = 0;
    while ((!r.empty() + !g.empty() + !b.empty()) >= 2)
    {
        ans += rect_area(r, g, b);
    }
    cout << ans << endl;
    return 0;
}