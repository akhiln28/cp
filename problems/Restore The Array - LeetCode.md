---
Created Time: Dec 19, 2020 2:47 PM
Do Date: Dec 19, 2020
Last edited time: Mar 01, 2021 8:48 AM
Points: 1800
Pomos (25 mins): 1
Related To: Decode%20Ways%20-%20LeetCode%2062637e7bf9e94d8da4dc17606744d6d2.md
Source: https://leetcode.com/problems/restore-the-array/
Status: done
Tags: counting dp
---

# Restore The Array - LeetCode

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits and all we know is that all integers in the array were in the range `[1, k]` and there are no leading zeros in the array.
Given the string `s` and the integer `k`. There can be multiple ways to restore the array.
Return *the number of possible array* that can be printed as a string `s` using the mentioned program.
The number of ways could be very large so return it **modulo** `10^9 + 7`
**Example 1:**
```
Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
```
**Example 2:**
```
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
```
**Example 3:**
```
Input: s = "1317", k = 2000
Output: 8
```
**Example 4:**
```
Input: s = "2020", k = 30
Output: 1
Explanation: The only possible array is [20,20]. [2020] is invalid because 2020 > 30. [2,020] is ivalid because 020 contains leading zeros.
```
**Example 5:**
```
Input: s = "1234567890", k = 90
Output: 34
```
**Constraints:**
- `1 <= s.length <= 10^5`.
- `s` consists of only digits and doesn't contain leading zeros.
- `1 <= k <= 10^9`.
---
```cpp
class Solution {
public:
    const int mod = 1e9 + 7; 
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<long long> dp(n); 
        dp[0] = (s[0] != '0'); 
        if (!dp[0]) return false; 
        for (int i = 1; i < n; i++)
        {
            // consider the number from j to i inclusive
            long long factor = 1; 
            int j = i; 
            long long sum = s[i] - '0'; 
            while (j >= 0 and sum <= k)
            {
                if (s[j] != '0') dp[i] = ((j?dp[j - 1]:1) + dp[i]) % mod; 
                if (!j or factor > 1e9) break;
                factor *= 10; 
                sum += factor * (s[j - 1] - '0'); 
                j--; 
            }
        }
        return dp[n - 1]; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)