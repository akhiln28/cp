```cpp
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

/*
    title: random_inputs.cpp
    author: Akhil
    date: 2021-04-23
    time: 21:36:50
    ==================================================
    The aim of this file is to generate random inputs of various types.
    Given an input format generate some test cases for that.
*/
int main()
{
    srand(time(0));
    string type = "array";
    if (type == "array") {
        int n = 1;
        const int maxe = 3;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = rand() % maxe;
        }
        cout << n << endl;
        for (int i = 0; i < n; i++) cout << v[i] << " "; cout << endl;
    } else if (type == "graph") {

    }
    return 0;
}
```
