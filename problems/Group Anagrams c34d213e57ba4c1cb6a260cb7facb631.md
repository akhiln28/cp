# Group Anagrams

Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 18, 2021
Last edited time: May 11, 2021 8:58 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Status: done

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lower-case English letters.

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> v(26);
            for (int j = 0; j < strs[i].length(); j++)
            {
                v[strs[i][j] - 'a']++;
            }
            mp[v].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
            ans.push_back(it.second);
        return ans;
    }
};
```