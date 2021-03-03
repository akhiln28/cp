/*
    title: a.cpp
    author: Akhil
    date: 2020-12-30
    time: 20:08:26
*/

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
        set<double> s; 
        vector<int> v(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i]; 
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double area = 1/2.0 * (v[j] - v[i]);
                s.insert(area); 
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}