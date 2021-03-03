
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
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
    int num_cases; cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n; cin >> n; 
        vector<int> v(101); 
        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x; 
            v[x]++; 
        }
        cout << *max_element(v.begin(), v.end()) << endl;
    }
    return 0;
}