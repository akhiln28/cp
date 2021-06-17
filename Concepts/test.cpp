#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void combination(vector<vector<int>> &all, vector<int> &ans, vector<int> &arr, int i)
{
    if (i == arr.size()) 
    {
        all.push_back(ans);
        return;
    }
    combination(all, ans, arr, i + 1); 
    ans.push_back(arr[i]); 
    combination(all, ans, arr, i + 1); 
    ans.pop_back(); 
}

vector<vector<int>> all_combinations(vector<int> &arr)
{
    vector<vector<int>> all; 
    vector<int> ans; 
    combination(all, ans, arr, 0); 
    return all; 
}

int main()
{
    auto start = high_resolution_clock::now();
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto ans = all_combinations(v);
    cout << "size: " << ans.size() << endl; 
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " "; 
    //     cout << endl; 
    // }
    auto end = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}