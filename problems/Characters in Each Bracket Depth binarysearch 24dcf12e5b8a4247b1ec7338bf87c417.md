# Characters in Each Bracket Depth | binarysearch

Created Time: Feb 18, 2021 1:17 PM
Do Date: Feb 18, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1500
Pomos (25 mins): 2
Source: https://binarysearch.com/problems/Characters-in-Each-Bracket-Depth
Status: done

You are a given a string `s` containing `"X"`, `"("`, and `")"`. The string has balanced brackets and in between there are some `"X"`s along with possibly nested brackets recursively.

Return the number of `"X"`s at each depth of brackets in `s`, from the shallowest depth to the deepest depth.

**Constraints**

- `2 ≤ n ≤ 100,000` where `n` is the length of `s`

****Input****

`s = "(XX(XX(X))X)"`

****Output****

`[3, 2, 1]`

### **Explanation**

There's three `"X"`s at depth `0`. Two `"X"`s at depth `1`. And one `"X"` at depth `2`.

### **Example 2**

****Input****

`s = "(())"`

****Output****

`[0, 0]`

### **Explanation**

There's no `"X"`s but depth goes to `1`.

---

Easy solution, 

```cpp
vector<int> solve(string s) {
    unordered_map<int,int> mp; 
    int depth = -1, max_depth = 0; 
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') depth++; 
        else if (s[i] == ')') depth--;
        else if (s[i] == 'X') 
        {
            mp[depth]++;
        }
        max_depth = max(max_depth, depth); 
    }
    vector<int> ans(max_depth + 1); 
    for (auto [k, v] : mp)
    {
        ans[k] = v;
    }
    return ans; 
}
```

- Initial Solution (recursive approach, failed)

    ```cpp
    void func(string& s, int i, int j, int depth, vector<int>& counts)
    {
        cout << i << " " << j << endl;
        if (i >= j) 
        {
            return; 
        }
        int x = i, y = j; 
        int count = 0; 
        for (x = i + 1; x < j; x++)
        {
            if (s[x] == '(') break;
            else if (s[x] == 'X') count++; 
        }
        for (y = j - 1; y > i; y--)
        {
            if (s[y] == ')') break; 
            else if (s[y] == 'X') count++; 
        }
        if (x == j or y == i) count /= 2; 
        if (depth >= counts.size())
        {
            counts.resize(depth + 1); 
            counts[depth] += count;
        }
        else counts[depth] += count;
        func(s, x, y, depth + 1, counts); 
    }

    vector<int> solve(string s) {
        vector<int> counts;   
        func(s, 0, s.length() - 1, 0, counts); 
        return counts; 
    }
    ```