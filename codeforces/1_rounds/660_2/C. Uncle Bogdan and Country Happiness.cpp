#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

class node
{
public:
    int idx;
    int total, p;
    int good, bad, happiness;
    node *parent;
    node(int idx, int p)
    {
        this->p = p;
        this->idx = idx;
        this->parent = nullptr;
        this->total = 0;
    }
};

void traverse_root(node *nod)
{
    node *ptr = nod;
    while (ptr)
    {
        ptr->total += nod->p;
        ptr = ptr->parent;
    }
}

bool compute_good_bad(node *nod)
{
    if (nod->total + nod->happiness & 1) return false;
    nod->good = (nod->total + nod->happiness)/2;
    nod->bad = (nod->total - nod->happiness)/2;
    if (nod->good >= 0 && nod->bad >= 0) return true;
    else return false;
}

bool check_bad_with_parent(node *nod)
{
    if (nod->parent)
        return nod->bad >= nod->parent->bad;
    else return true;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;
        vector<node *> v(n);

        for (size_t i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            v[i] = new node(i, p);
        }
        for (size_t i = 0; i < n; i++)
        {
            int happiness;
            cin >> happiness;
            v[i]->happiness = happiness;
        }
        for (size_t i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            v[y - 1]->parent = v[x - 1];
        }
        for (size_t i = 0; i < n; i++)
        {
            traverse_root(v[i]);
        }
        int flag = true;
        for (size_t i = 0; i < n; i++)
        {
            flag = compute_good_bad(v[i]);
            if (!flag)
                break;
        }
        if (flag)
        {
            for (size_t i = 0; i < n; i++)
            {
                flag = check_bad_with_parent(v[i]);
                if (!flag)
                    break;
            }
            if (flag)
                cout << "YES" << endl;
            else cout << "NO2" << endl;
        }
        else cout << "NO1" << endl;
    }
    return 0;
}