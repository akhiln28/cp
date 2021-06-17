# Stepping Numbers - GeeksforGeeks

Created Time: Jan 16, 2021 4:01 PM
Do Date: Jan 20, 2021
Last edited time: Apr 08, 2021 8:12 AM
Pattern: https://www.notion.so/DFS-ba39c3dceb894d178f88767d81fa001a, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9
Points: 1600
Pomos (25 mins): 3
Related To: Lexicographical%20Numbers%20-%20LeetCode%205199ab31a1cb456aa592e5d7cb8549e3.md
Source: https://www.geeksforgeeks.org/stepping-numbers/
Status: done
Tags: amazon

Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m]. A number is called **stepping number** if all adjacent digits have an absolute difference of 1. 321 is a Stepping Number while 421 is not.**Examples :**

```
Input : n = 0, m = 21
Output : 0 1 2 3 4 5 6 7 8 9 10 12 21

Input : n = 10, m = 15
Output : 10, 12
```

---

Using dfs. The neighbours of x are 10 * x + (last digit + 1) and 10 * x + (last digit - 1)

```jsx
class Solution{
public:
    int steppingNumbers(int n, int m)
    {
        stack<int> st; 
        for (int i = 0; i < 10; i++) st.push(i); 
        int count = 0; 
        unordered_set<int> se; 
        while (st.size())
        {
            int top = st.top(); 
            st.pop();
            se.insert(top); 
            if (top > m) continue; 
            if (top >= n) 
            {
                count++;
            }
            if (top % 10 != 0) 
            {
                int left = 10 * top + (top % 10 - 1); 
                if (se.count(left) == 0)
                    st.push(left);
            }
            if (top % 10 != 9)
            {
                int right = 10 * top + (top % 10 + 1);
                if (se.count(right) == 0)
                    st.push(right);
            }
        }
        return count; 
    }
};
```