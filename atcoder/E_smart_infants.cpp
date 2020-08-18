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
#define max_n 200005
using namespace std;

// https://atcoder.jp/contests/abc170/tasks/abc170_e


int main()
{
    int n, q; cin >> n >> q;
    vector<int> ratings(n + 1), kg(n + 1);
    map<int, multiset<int>> kgs;
    multiset<int> evenness;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        ratings[i + 1] = a;
        kg[i + 1] = b;
        kgs[b].insert(a);
    }

    for (auto kg : kgs)
    {
        if (kg.second.size())
        {
            int max_element = *kg.second.rbegin();
            evenness.insert(max_element);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int c, d; cin >> c >> d;
        int pkg = kg[c], rating = ratings[c];
        kg[c] = d;
        // removing from previous
        auto it_pkg = kgs[pkg].find(rating);
        if (rating == *kgs[pkg].rbegin())
        {
            evenness.erase(evenness.find(rating));
            kgs[pkg].erase(it_pkg);
            if (!kgs[pkg].empty())
            {
                evenness.insert(*kgs[pkg].rbegin());
            }
        }
        else kgs[pkg].erase(it_pkg);
        // inserting into new one
        if (kgs[d].size() && rating > *kgs[d].rbegin())
        {
            evenness.erase(evenness.find(*kgs[d].rbegin()));
            evenness.insert(rating);
        }
        if (kgs[d].empty()) evenness.insert(rating);
        kgs[d].insert(rating);
        cout << *evenness.begin() << endl;
    }
    return 0;     
}