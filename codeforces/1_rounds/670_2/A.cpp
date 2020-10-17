#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int T; cin >> T; 
    for (int t = 0; t < T; t++)
    {
        int n; cin >> n;
        vector<int> v(101); 
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x; 
            v[x]++;
        }
        int ans = 0; 
        int i = 0; 
        while (v[i] == 2)
        {
            i++;
        }
        ans += i;
        int j = i;
        while (v[j] == 1)
        {
            j++;
        }
        ans += j;
        cout << ans << endl;
    }
}