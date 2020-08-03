#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

#define max_n 200001

struct tripllle
{
public:
    int time;
    bool alice;
    bool bob;
    tripllle(int time, bool alice, bool bob)
    {
        this->time = time;
        this->alice = alice;
        this->bob = bob;
    }
};

using namespace std;

int main()
{
    int n, k, t;
    bool alice, bob;
    cin >> n >> k;
    vector<tripllle> v;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> alice >> bob;
        tripllle tr(t, alice, bob);
        v.push_back(tr);
    }
    sort(v.begin(), v.end());
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i].time << " ";
    }
    cout << endl;

    return 0;
}