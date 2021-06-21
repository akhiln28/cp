---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Mar 09, 2021
Last edited time: May 11, 2021 8:58 AM
Points: 1600
Status: ok
Tags: window
---

# Window Queries

You are given two lists of integers `nums` and `queries`. You are also given an integer `w`. Return a new list where for each query `q` in `queries`, we answer the question of how many number of different ways are there for a window of length `w` to cover an element with value `q`.
**Constraints**
- `n ≤ 100,000` where `n` is the length of `nums`
- `m ≤ n` where `m` is the length of `queries`
- `0 ≤ nums[i] < n`
- `0 ≤ queries[i] < n`
### **Example 1**
****Input****
`nums = [2, 1, 2, 3, 4]`
`queries = [2, 1]`
`w = 3`
****Output****
`[3, 2]`
### **Explanation**
For the first query, we ask how many ways are there for a window of length `3` to contain the value `2`. There are three ways:
- `[2, 1, 2]`
- `[1, 2, 3]`
- `[2, 3, 4]`
For the second query, we ask how many ways are there for a window of length `3` to contain the value `1`. There are two ways:
- `[2, 1, 2]`
- `[1, 2, 3]`
### **Example 2**
****Input****
`nums = [2, 2, 2]`
`queries = [2]`
`w = 2`
****Output****
`[2]`
### **Explanation**
The two ways are `[2, 2]` and `[2, 2]`.
---
```cpp
vector<int> solve(vector<int>& nums, vector<int>& queries, int w) {
    unordered_map<int, vector<int>> mp; 
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i); 
    }
    unordered_map<int, int> mp1; 
    for (auto p : mp)
    {
        int prev = 0; 
        int ans = 0; 
        vector<int> &v = p.second;
        for (int i = 0; i < v.size(); i++)
        {
            ans += max(0, (min(v[i], (int) nums.size() - w) - max(prev, v[i] - w + 1) + 1));
            prev = v[i] + 1; 
        }
        mp1[p.first] = ans; 
    }
    vector<int> ans; 
    for (int i = 0; i < queries.size(); i++)
    {
        if (mp1.find(queries[i]) != mp1.end()) ans.push_back(mp1[queries[i]]);
    }
    return ans;
}
```
Patterns: [Matrix](Matrix.md)[Hashing](Hashing.md)