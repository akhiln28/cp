# K-diff Pairs in an Array

Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 25, 2021
Last edited time: Feb 25, 2021 8:13 AM
Pattern: https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Status: done

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        unordered_map<int, int> mp; 
        int ans = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (i and nums[i] == nums[i - 1]) 
            {
                mp[nums[i]]++; continue;
            } 
            if (mp.find(nums[i] - k) != mp.end()) ans++;
            mp[nums[i]]++; 
        }
        if (k == 0)
        {
            for (auto it : mp) ans += it.second >= 2; 
        }
        return ans; 
    }
};
```