---
Created Time: Jan 04, 2021 9:11 PM
Last edited time: May 20, 2021 9:56 AM
Status: waiting
---

# Amazon online assessment

![Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled.png](Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled.png)
![Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%201.png](Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%201.png)
![Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%202.png](Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%202.png)
![Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%203.png](Amazon%20online%20assessment%20419e76930af24463a7ad18a3257212a3/Untitled%203.png)
```jsx
#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
/*
 * Complete the 'applicationPairs' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER deviceCapacity
 *  2. 2D_INTEGER_ARRAY foregroundAppList
 *  3. 2D_INTEGER_ARRAY backgroundAppList
 */
vector<vector<int>> applicationPairs(int deviceCapacity, vector<vector<int>> foregroundAppList, vector<vector<int>> backgroundAppList) {
    long long int min_ans = INT_MAX, n = foregroundAppList.size(), m = backgroundAppList.size(); 
    // cout << "foreground" << endl;
    vector<long long int> v1(n), v2(m); 
    for (int i = 0; i < n; i++)
    {
        v1[i] = foregroundAppList[i][1]; 
        // cout << foregroundAppList[i][0] << " " << foregroundAppList[i][1] << endl;
    }
    // cout << "background" << endl;
    for (int i = 0; i < m ; i++)
    {
        v2[i] = backgroundAppList[i][1]; 
        // cout << backgroundAppList[i][0] << " " << backgroundAppList[i][1] << endl;
    }
    // cout << "device capacity: " << deviceCapacity << endl;
    // for (int i = 0; i < n; i++) cout << v1[i] << " "; cout << endl;
    // for (int i = 0; i < m; i++) cout << v2[i] << " "; cout << endl;
    
    sort(v1.begin(), v1.end()); 
    sort(v2.begin(), v2.end()); 
    int i = 0, j = m - 1; 
    while (i < n and j >= 0)
    {
        if (v1[i] + v2[j] < deviceCapacity)
        {
            min_ans = min(min_ans, deviceCapacity - v1[i] - v2[j]); 
            i++; 
        }
        else if (v1[i] + v2[j] > deviceCapacity)
        {
            j--; 
        }
        else {
            min_ans = 0; 
            break;
        }
    }
    if (min_ans == INT_MAX) return {{}}; 
    // cout << min_ans << endl;
    unordered_map<int, vector<int>> mp2;
    for (int i = 0; i < m; i++)
    {
        mp2[backgroundAppList[i][1]].push_back(backgroundAppList[i][0]); 
    }
    vector<vector<int>> ans; 
    for (int i = 0; i < n; i++)
    {
        if (mp2.find(deviceCapacity - min_ans - foregroundAppList[i][1]) != mp2.end())
        {
            vector<int>& v = mp2[deviceCapacity - min_ans - foregroundAppList[i][1]];
            if (v.size() == 0) continue; 
            ans.push_back({foregroundAppList[i][0], v.back()});
            v.pop_back(); 
        }
    }
    return ans; 
}
int main()
```
Patterns: 