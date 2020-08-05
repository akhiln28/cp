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

class node {
    public:
    int idx;
    int total, p;
    int good, bad, happiness;
    node(int idx, int p)
    {
        this->p = p;
        this->idx = idx;
    }
};

void compute_good_bad(node *nod)
{

}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m; cin >> n >> m;
        vector<node*> v(n);
        for (size_t i = 0; i < n; i++)
        {
            int p; cin >> p;
            v[i] = new node(i, p);
        }
        for (size_t i = 0; i < n; i++)
        {
            int happiness; cin >> happiness;
            v[i]->happiness = happiness;
        }
        
    }

    return 0;
}