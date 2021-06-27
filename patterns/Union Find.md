---
Count: 2
Created Time: Apr 06, 2021 8:25 AM
Last Edit Time: Apr 06, 2021 8:25 AM
---
# Union find
```cpp
class union_find
{
    vector<int> parent, size;
    int components;

    union_find(int n) : parent(n), size(n, 1)
    {
        components = n;
        iota(parent.begin(), parent.end(), 0);
    }

    // returns the group (parent) in which x belongs
    int find(int x)
    {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y)
    {
        int parentx = find(x), parenty = find(y);
        if (parentx == parenty) return false;
        if (size[parentx] > size[parenty])
        {
            parent[parenty] = parentx;
            size[parentx] += size[parenty];
        }
        else
        {
            parent[parentx] = parenty;
            size[parenty] += size[parentx];
        }
        return true;
    }
};

```
Patterns: 