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
#define max_n 200001
using namespace std;

// https://atcoder.jp/contests/abc170/tasks/abc170_e

class kindergarten;
class infant;

class infant
{
public:
    int inf_id, rating;
    kindergarten *kg;
    infant(int inf_id, int rating)
    {
        this->inf_id = inf_id;
        this->rating = rating;
    }
    bool operator<(infant const &inf1) const
    {
        return this->rating < inf1.rating;
    }
};

class kindergarten
{
public:
    int id, max;
    set<infant> infants; // pair of rating id
    kindergarten(int id)
    {
        this->id = id;
    }
    void add_child(infant &inf)
    {
        infants.insert(inf);
        inf.kg = this;
    }
    void remove_child(infant &inf)
    {
        infants.erase(inf);
    }
    bool operator<(kindergarten const &kg) const
    {
        auto max1 = infants.size() ? prev(infants.end())->rating : INT_MAX;
        auto max2 = kg.infants.size() ? prev(kg.infants.end())->rating : INT_MAX;
        return max1 < max2;
    }
};

int main()
{
    kindergarten *kgs[max_n];
    set<kindergarten> kgsset;
    int n, q;
    cin >> n >> q;
    infant *infs[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        int x, y;
        cin >> x >> y;
        infant *inf = new infant(i, x);
        infs[i] = inf;
        if (!kgs[y])
        {
            kindergarten *kg = new kindergarten(y);
            kgs[y] = kg;
            kgsset.insert(*kg);
        }
        kgs[y]->add_child(*inf);
        inf->kg = kgs[y];
    }
    for (int i = 0; i < q; i++)
    {
        int c, d;
        cin >> c >> d;
        infant *inf = infs[c];
        kindergarten *kg1 = inf->kg, *kg2 = nullptr;
        if (!kgs[d])
        {
            kg2 = new kindergarten(d);
            kgs[d] = kg2;
            kgsset.insert(*kg2);
        }
        kg1->remove_child(*inf);
        kg2->add_child(*inf); 
        cout << prev(kgsset.begin()->infants.end())->rating << endl;
    }
}