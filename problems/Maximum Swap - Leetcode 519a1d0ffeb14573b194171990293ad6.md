# Maximum Swap - Leetcode

Created Time: Feb 16, 2021 8:51 AM
Do Date: Feb 16, 2021
Last edited time: Apr 08, 2021 8:12 AM
Pattern: https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/maximum-swap/
Status: done

Given a non-negative integer, you could swap two digits **at most** once to get the maximum valued number. Return the maximum valued number you could get.

**Example 1:**

```
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

```

**Example 2:**

```
Input: 9973
Output: 9973
Explanation: No swap.

```

**Note:**

1. The given number is in the range [0, 10^8]

---

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num); 
        int idx = -1, maxe = 0, n = str.length();
        
				// find suffix maximum
        vector<char> suff(str.length());
        suff[n - 1] = str[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = max(str[i], suff[i + 1]); 
        }
        
				// idx is the index which can be swapped with a larger character
        idx = 0; 
        ****while (idx < str.length() and str[idx] >= suff[idx]) idx++;
        if (idx == str.length()) return atoi(str.c_str());
        
        int idx1 = -1; 
        for (int i = idx + 1; i < str.length(); i++)
        {
            if (maxe <= str[i]) 
            {
                maxe = str[i]; 
                idx1 = i; 
            }
        }
				// swap the maximum which is farthest
        swap(str[idx], str[idx1]); 
        return atoi(str.c_str());
    }
};
```