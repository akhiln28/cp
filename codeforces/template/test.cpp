#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric> 
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
    vector<int> v{1, 3, 9, 91, 1, 27};
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";   
    }
}