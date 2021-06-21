---
Created Time: Dec 19, 2020 4:10 PM
Do Date: Feb 04, 2021
Last edited time: May 11, 2021 9:05 AM
Points: 1700
Pomos (25 mins): 3
Source: https://leetcode.com/problems/can-i-win/
Status: done
Tags: game, logic
---

# Can I Win - LeetCode

In the "100 game" two players take turns adding, to a running total, any integer from `1` to `10`. The player who first causes the running total to **reach or exceed** 100 wins.
What if we change the game so that players **cannot** re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
Given two integers maxChoosableInteger and desiredTotal, return `true` if the first player to move can force a win, otherwise return `false`. Assume both players play **optimally**.
**Example 1:**
```
Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
```
**Example 2:**
```
Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true
```
**Example 3:**
```
Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true
```
**Constraints:**
- `1 <= maxChoosableInteger <= 20`
- `0 <= desiredTotal <= 300`
---
Total to reach is T. max number is n. We have a pool ${1, 2, ..., n}$. 
```python
def (T, set{1, ..., n}) -> bool:
		if (max in set >= T) return true; 
		else if (T - min <= max) return false;
		else
				ans = False;
				for e in set: 
						ans = ans or func(T - e, set - {e})
				return ans; 
```
Simulation vs logic (taking many examples)
```jsx
class Solution {
public:
    unordered_map<int, bool> mp; 
    int find_hash(vector<bool>& nums)
    {
        int ans = 0; 
        for (int i = 1; i < nums.size(); i++)
        {
            ans += nums[i] * (1 << i); 
        }
        return ans; 
    }
    bool func(int T, vector<bool>& nums)
    {
        if (T <= 0) return false;
        int hash = find_hash(nums);
        if (mp.find(hash) == mp.end())
        {
            bool ans = false; 
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] == false)
                {
                    nums[i] = true; 
                    ans = !func(T - i, nums);
                    nums[i] = false; 
                }
                if (ans) 
                {
                    mp[hash] = true; 
                    break;
                }
            }
        }
        return mp[hash]; 
    }
    bool canIWin(int maxInteger, int desiredTotal) {
        mp.clear(); 
        if (desiredTotal == 0) return true; 
        if (maxInteger * (maxInteger + 1) / 2 < desiredTotal) return false; 
        vector<bool> nums(maxInteger + 1);
        return func(desiredTotal, nums); 
    }
};
```
Complexity: $2^n$
Patterns: [Matrix](Matrix.md)[Backtracking](Backtracking.md)