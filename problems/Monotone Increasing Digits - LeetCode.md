---
Created Time: Feb 16, 2021 8:35 AM
Do Date: Feb 16, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/monotone-increasing-digits/
Status: done
---

# Monotone Increasing Digits - LeetCode

Given a non-negative integer `N`, find the largest number that is less than or equal to `N` with monotone increasing digits.
(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits `x` and `y` satisfy `x <= y`.)
**Example 1:**
```
Input: N = 10
Output: 9
```
**Example 2:**
```
Input: N = 1234
Output: 1234
```
**Example 3:**
```
Input: N = 332
Output: 299
```
**Note:** `N` is an integer in the range `[0, 10^9]`.
---
```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // vector of digits of N
        vector<int> digits; 
        int n = N; 
        while (n)
        {
            digits.push_back(n % 10); 
            n /= 10; 
        }
        reverse(digits.begin(), digits.end());
        
        int idx = -1; 
        for (int i = 0; i < digits.size(); i++)
        {
            if (i + 1 < digits.size() and digits[i] > digits[i + 1])
            {
                idx = i; 
                while (idx and digits[idx] == digits[idx - 1])
                {
                    idx--;
                }
                break; 
            }
        }
        cout << idx << endl;
        if (idx != -1)
        {
            digits[idx]--; 
            for (int i = idx + 1; i < digits.size(); i++)
                digits[i] = 9;
        }
        int ans = 0, factor = 1; 
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            ans += digits[i] * factor; 
            factor *= 10; 
        }
        return ans; 
    }
};
```
The same solution but fewer lines of code,
```cpp
class Solution {
    public int monotoneIncreasingDigits(int N) {
        char[] S = String.valueOf(N).toCharArray();
        int i = 1;
        while (i < S.length && S[i-1] <= S[i]) i++;
        while (0 < i && i < S.length && S[i-1] > S[i]) S[--i]--;
        for (int j = i+1; j < S.length; ++j) S[j] = '9';
        return Integer.parseInt(String.valueOf(S));
    }
}
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)