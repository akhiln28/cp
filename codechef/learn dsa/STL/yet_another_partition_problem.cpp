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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<pair<int, int>> sets;
    sets.insert(make_pair(0, 1));
    for (size_t i = 1; i < n; i++)
    {
        cin >> a[i];
        auto last_element = *prev(sets.end());
        auto top = a[last_element.first + last_element.second - 1];
        if (a[i] % top == 0)
        {
            sets.erase(prev(sets.end()));
            last_element.second++;
            sets.insert(last_element);
        }
        else
        {
            sets.insert(make_pair(i, 1));
        }
    }
    for (size_t i = 0; i < q; i++)
    {
        int qtype, idx, x;
        cin >> qtype >> idx;
        auto it = sets.lower_bound(make_pair(idx, 0));
        if (it->first > idx)
            it--;
        auto prevs = prev(it); it++, it++;
        auto next = it; it--;

        if (qtype == 1)
        {
            cin >> x;
            a[idx] = x;
            auto cur = *it;
            sets.erase(it);
            if (idx - 1 >= cur.first && idx + 1 <= cur.first + cur.second - 1)
            {
                if (a[idx] % a[idx - 1] != 0 && a[idx + 1] % a[idx] != 0)
                {
                    sets.insert(make_pair(cur.first, idx - cur.first));
                    sets.insert(make_pair(idx, 1));
                    sets.insert(make_pair(idx + 1, cur.second - idx));
                }
                else if (a[idx] % a[idx - 1] == 0 && a[idx + 1] % a[idx] != 0)
                {
                    sets.insert(make_pair(cur.first, idx - cur.first + 1));
                    sets.insert(make_pair(idx + 1, cur.second - idx));
                }
                else if (a[idx] % a[idx - 1] != 0 && a[idx + 1] % a[idx] == 0)
                {
                    sets.insert(make_pair(cur.first, idx - 1 - cur.first + 1));
                    sets.insert(make_pair(idx + 1, cur.second - idx));
                }
                else
                {
                    sets.insert(cur);
                }
                
            }
            else if (idx - 1 >= cur.first && idx == cur.first + cur.second - 1)
            {
                if (a[idx] % a[idx - 1] != 0) 
                {
                    sets.insert(make_pair(idx, 1));
                    sets.insert(make_pair(cur.first, cur.second - 1));
                }
                else sets.insert(cur);
            }
            else if (idx == cur.first && idx + 1 <= cur.first + cur.second - 1)
            {
                if (a[idx + 1] % a[idx] != 0)
                {
                    sets.insert(make_pair(idx, 1));
                    sets.insert(make_pair(idx + 1, cur.second - 1));
                }
                else sets.insert(cur);
            }
            else
            {
                if (idx - 1 >= 0 && idx + 1 <= n - 1)
                {
                    if ()
                }
                if (idx - 1 >= 0 && idx + 1 <= n - 1)
                {
                }
                if (idx - 1 >= 0 && idx + 1 <= n - 1)
                {
                }
                if (idx - 1 >= 0 && idx + 1 <= n - 1)
                {
                }
                    
            }
        }
        else
        {
        }
    }
}