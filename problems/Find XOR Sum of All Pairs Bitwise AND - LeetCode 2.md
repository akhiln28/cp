---
Created Time: Apr 17, 2021 10:34 PM
Day Completed: https://www.notion.so/18-April-21-daf97facd99747cf98fad04b29f42a7e
Last edited time: Apr 17, 2021 10:35 PM
Points: 1800
Source: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
Status: done
---

# Find XOR Sum of All Pairs Bitwise AND - LeetCode

![LeetCode_Sharing.png](Find%20XOR%20Sum%20of%20All%20Pairs%20Bitwise%20AND%20-%20LeetCode%2071e449cdb6e04f36b8025a9bb86d6304/LeetCode_Sharing.png)
The **XOR sum** of a list is the bitwise `XOR` of all its elements. If the list only contains one element, then its **XOR sum** will be equal to this element.
- For example, the **XOR sum** of `[1,2,3,4]` is equal to `1 XOR 2 XOR 3 XOR 4 = 4`, and the **XOR sum** of `[3]` is equal to `3`.
You are given two **0-indexed** arrays `arr1` and `arr2` that consist only of non-negative integers.
Consider the list containing the result of `arr1[i] AND arr2[j]` (bitwise `AND`) for every `(i, j)` pair where `0 <= i < arr1.length` and `0 <= j < arr2.length`.
Return *the **XOR sum** of the aforementioned list*.
**Example 1:**
```
Input: arr1 = [1,2,3], arr2 = [6,5]
Output: 0
Explanation: The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.
```
**Example 2:**
```
Input: arr1 = [12], arr2 = [4]
Output: 4
Explanation: The list = [12 AND 4] = [4]. The XOR sum = 4.
```
**Constraints:**
- `1 <= arr1.length, arr2.length <= 105`
- `0 <= arr1[i], arr2[j] <= 109`
---
```cpp
class Solution {
public:
    vector<int> getbinary(int n)
    {
        vector<int> ans(32);
        int i = 31; 
        while (n)
        {
            ans[i] = (n % 2); 
            i--; 
            n /= 2; 
        }
        return ans; 
    }
    long long getvalue(vector<int> v)
    {
        long long f = 1; 
        long long ans = 0; 
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += f * v[i]; 
            f *= 2; 
        }
        return ans; 
    }
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        // to be able to compute the xor of all the pair wise ands without actually computing pair wise ands in O(n)
        // complexity is O(m * n)
        // [1, 2, 3], [6, 5]
        // (1&6)^(1&5)^(2&6)^(2&5)^(3&5)^(3&6) 
        // (1&110)^(1&101)
        int n = arr1.size(); 
        int m = arr2.size(); 
        vector<int> counts(32); 
        for (int i = 0; i < m; i++)
        {
            auto bin = getbinary(arr2[i]); 
            for (int j = 0; j < 32; j++)
            {
                counts[j] += bin[j];
            }
        }
        // for (int i = 0; i < 32; i++) cout << counts[i] << " "; cout << endl;
        int ans = 0; 
        for (int i = 0; i < n; i++)
        {
            auto bin = getbinary(arr1[i]); 
            auto tempc = counts; 
            for (int j = 0; j < 32; j++)
            {
                if (bin[j] == 0) tempc[j] = 0; 
            }
            for (int j = 0; j < 32; j++)
            {
                tempc[j] %= 2; 
            }
            ans ^= getvalue(tempc); 
        }
        return ans; 
    }
};
```
Patterns: [Bits](Bits.md)