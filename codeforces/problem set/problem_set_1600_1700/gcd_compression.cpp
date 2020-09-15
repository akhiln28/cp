#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <list>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;
// pending
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        list<int> odds, evens;
        for (int i = 0; i < 2 * n; i++)
        {
            int x; cin >> x;
            if (x & 1) odds.push_back(x); 
            else evens.push_back(x);
        }
        if (odds.size() & 1) odds.pop_back(), evens.pop_back();
        else
        {
            if (evens.size()) evens.pop_back(), evens.pop_back();
            else odds.pop_back(), odds.pop_back();
        }
        for (auto it : odds) cout << it << endl;
        for (auto it : evens) cout << it << endl;
    }
}