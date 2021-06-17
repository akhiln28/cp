# Longest Substring with At Most K Distinct Characters - LeetCode

Created Time: Dec 18, 2020 4:40 PM
Do Date: Dec 18, 2020
Last edited time: May 11, 2021 9:00 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Problem Statement: Given a string, find the length of the longest substring which contains atmost K distinct characters?
Source: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
Status: ok
Tags: unverified

Given a string, find the length of the longest substring which contains atmost K distinct characters?

---

```cpp
int solve(string s, int k)
{
		int end = 0,n = s.length(); 
		map<int, int> mp; 
		
		mp[s[0]]++;
		int ans = 0;  
		for (int start = 0; start < n; start++)
		{
				while (end + 1 < n and mp.size() < k) mp[s[++end]]++; 
				while (end + 1 < n and mp.find(s[end + 1]) != mp.end()) mp[s[++end]]++; 
				ans = max(ans, end - start + 1); 
				if (mp[s[start]] == 1) mp.erase(s[start]); 
				else mp[s[start]]--; 
		}
		return ans; 
}
```