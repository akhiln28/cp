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
    node *parent;
    node(int idx)
    {
        this->idx = idx;
        parent = nullptr;
        referenceA = 0;
        referenceB = 0;
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
double probability(vector<node *> &v, int idx)
{
    int n = v.size() - 1;
    double probability = (double)(v[idx]->referenceA + v[idx]->referenceB) / n - (double)(v[idx]->referenceA * v[idx]->referenceB) / (n * n);
    cout << probability << endl;
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
        }

        double ans = 0;
        for (size_t i = 1; i <= n; i++)
        {
            ans += probability(v, i);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
