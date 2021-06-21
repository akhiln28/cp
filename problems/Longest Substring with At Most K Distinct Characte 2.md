---
Created Time: Dec 18, 2020 4:40 PM
Do Date: Dec 18, 2020
Last edited time: May 11, 2021 9:00 AM
Problem Statement: Given a string, find the length of the longest substring which contains atmost K distinct characters?
Source: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
Status: ok
Tags: unverified
---

# Longest Substring with At Most K Distinct Characters - LeetCode

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
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)