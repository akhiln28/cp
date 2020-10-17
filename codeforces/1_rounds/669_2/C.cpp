#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <list>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    long long n; cin >> n;
    list<int> ls;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        ls.push_back(i + 1);
    }
    while (ls.size() >= 2)
    {
        int i = ls.front(); ls.pop_front();
        int j = ls.front(); ls.pop_front();
        int a, b;
        cout << "? " << i << " " << j << endl;
        cin >> a; 
        cout << "? " << j << " " << i << endl;
        cin >> b;
        if (a < b) v[j - 1] = b, ls.push_front(i);
        else v[i - 1] = a, ls.push_front(j);
    }
    if (ls.size())
    {
        int i = ls.front(); 
        v[i - 1] = (n * (n + 1)) / 2 - accumulate(v.begin(), v.end(), 0);
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout.flush();
    return 0;
}