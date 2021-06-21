---
Created Time: Feb 23, 2021 8:19 AM
Do Date: Feb 25, 2021
Last edited time: Feb 25, 2021 8:55 AM
Points: 1500
Source: https://leetcode.com/problems/four-divisors/
Status: done
---

# Four Divisors - LeetCode

Given an integer array `nums`, return the sum of divisors of the integers in that array that have exactly four divisors.
If there is no such integer in the array, return `0`.
**Example 1:**
```
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
```
**Constraints:**
- `1 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^5`
---
- Process
    A number will have exactly four divisors if it is in the form $n = p * q \space or  \space n = p^3$
    We have to solve this question in linear or logarithmic time. 
    We can use prime factorization for each number. We quit when the number of factors is greater than four. 
```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // for each number, if it is a factor only two primes, then we add all its factors. 
        int res = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            int last_d = 0; 
            for (int d = 2; d * d <= nums[i]; d++)
            {
                if (nums[i] % d == 0)
                {
                    if (last_d == 0)
                    {
                        last_d = d; 
                    }
                    else
                    {
                        last_d = 0; 
                        break; 
                    }
                }
            }
            if (last_d and nums[i] / last_d != last_d)
            {
                res += 1 + nums[i] + last_d + nums[i]/last_d; 
            }
        }
        return res;
    }
};
```
Patterns: [Number%20Theory](Number%20Theory.md)