/*
    title: B.cpp
    author: Akhil
    date: 2020-10-24
    time: 19:45:43
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        int val = -1; 
        for (auto i : primes)
        {
            if (i - n + 1 > 0 and find(primes.begin(), primes.end(), i - n + 1) == primes.end())
            {
                val = i - n + 1; 
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) cout << val << " "; 
                else cout << 1 << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}
