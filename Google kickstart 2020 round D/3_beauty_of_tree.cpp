#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct node
{
public:
    int idx;
    int referenceA;
    int referenceB;
    int referenceAB;
    node *parent;
    node(int idx)
    {
        this->idx = idx;
        parent = nullptr;
        referenceA = 0;
        referenceB = 0;
        referenceAB = 0;
    }
};

void traverse_to_rootA(vector<node *> &v, int idx, int interval)
{
    int count = 0;
    node *ptr = v[idx];
    while (ptr)
    {
        if (count % interval == 0)
        {
            ptr->referenceA++;
        }
        ptr = ptr->parent;
        count++;
    }
}
void traverse_to_rootB(vector<node *> &v, int idx, int interval)
{
    int count = 0;
    node *ptr = v[idx];
    while (ptr)
    {
        if (count % interval == 0)
        {
            ptr->referenceB++;
        }
        ptr = ptr->parent;
        count++;
    }
}
void traverse_to_rootAB(vector<node *> &v, int idx, int interval)
{
    int count = 0;
    node *ptr = v[idx];
    while (ptr)
    {
        if (count % interval == 0)
        {
            ptr->referenceAB++;
        }
        ptr = ptr->parent;
        count++;
    }
}
float probability(vector<node *> v, int idx)
{
    int n = v.size() - 1;
    float probability = (float)(v[idx]->referenceA + v[idx]->referenceB) / n - (float)v[idx]->referenceAB / (n * n);
    return probability;
}
int main()
{
    int T;
    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<node *> v(n + 1);
        v[1] = new node(1);
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            v[i] = new node(i);
            v[i]->parent = v[x];
        }
        for (size_t i = 1; i <= n; i++)
        {
            traverse_to_rootA(v, i, a);
            traverse_to_rootB(v, i, b);
            traverse_to_rootAB(v, i, a * b);
        }
        for (size_t i = 1; i <= n; i++)
        {
            cout << v[i]->referenceAB << endl;
        }

        float ans = 0;
        for (size_t i = 1; i <= n; i++)
        {
            ans += probability(v, i);
        }
        cout << ans << endl;
    }

    return 0;
}
