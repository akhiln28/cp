/*
    title: save_konoha.cpp
    author: Akhil Nichenametla
    source: https://www.codechef.com/LRNDSA03/problems/SAVKONO
    date: 2020-08-06
    time: 17:59:55
*/

/*
Sample Input:
1
5 100
10 9 8 7 6
*/

#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int T;
    cin >> T;
    F(t, 1, T + 1)
    {
        int n, z;
        cin >> n >> z;
        multiset<int> s;
        F(i, 0, n)
        {
            int x; cin >> x;
            s.insert(x);
        }
        int count = 0;
        bool win = true;
        while (z > 0)
        {
            if (s.empty())
            {
                win = false;
                break;
            }
            auto it = s.end(); it--;
            z -= *it; count++;
            if (*it >= 2)
                s.insert(*it/2);
            s.erase(it);
        }
        if (win) cout << count << endl;
        else cout << "Evacuate" << endl;
    }
    return 0;
}