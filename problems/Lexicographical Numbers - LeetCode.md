---
Created Time: Jan 04, 2021 7:09 PM
Do Date: Jan 19, 2021
Last edited time: Mar 01, 2021 8:48 AM
Points: 1600
Relates: Stepping%20Numbers%20-%20GeeksforGeeks%2055ff57ad440546f2922abbc43bf4d64a.md
Source: https://leetcode.com/problems/lexicographical-numbers/
Status: done
---

# Lexicographical Numbers - LeetCode

Given an integer n, return 1 - n in lexicographical order.
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
---
```jsx
class Solution {
public:
    void traverse(int x, int n, vector<int>& ans)
    {
        if (x > n) return; 
        ans.push_back(x);
        for (int i = 0; i < 10; i++)
        {
            traverse(x * 10 + i, n, ans); 
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans; 
        for (int i = 1; i < 10; i++)
        {
            traverse(i, n, ans); 
        }
        return ans; 
    }
};
```
Using stack 
```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        stack<int> st; 
        vector<int> ans; 
        for (int i = min(9, n); i >= 1; i--) st.push(i);
        while (st.size())
        {
            int x = st.top();
            ans.push_back(x); 
            st.pop();
						// push all the neighbours
            for (int i = 10 * x + 9; i >= 10 * x; i--)
            {
                if (i <= n) st.push(i); 
            }
        }
        return ans; 
    }
};
```
Patterns: [DFS](DFS.md)[Dp](Dp.md)