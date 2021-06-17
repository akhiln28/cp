# Compressed Vector Product | binarysearch

Created Time: Mar 08, 2021 8:58 AM
Do Date: Mar 09, 2021
Last edited time: Mar 09, 2021 8:17 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74
Points: 1500
Source: https://binarysearch.com/problems/Compressed-Vector-Product
Status: done

You are given two integer lists `a` and `b` where each list represents a vector in run-length encoded form. For example, a vector `[1, 1, 1, 1, 2, 2, 2, 2, 2]` is represented as `[4, 1, 5, 2]`. (There are `4` ones and `5` twos.)

Return the dot product of the two vectors `a` and `b`.

The dot product of a vector `[x1, x2, ..., xn]` and `[y1, y2, ..., yn]` is defined to be `x1 * y1 + x2 * y2 + ... + xn * yn`.

**Constraints**

- `1 ≤ n ≤ 200,000` where `n` is the length of `a`
- `1 ≤ m ≤ 200,000` where `m` is the length of `b`

### **Output**

### **Explanation**

`a • b = [1, 1, 1, 1, 2, 2, 2, 2, 2] • [2, 2, 2, 2, 2, 2, 2, 2, 2]`

---

```java
int solve(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0; 
    int ans = 0; 
    while (i < a.size() and j < b.size())
    {
        if (a[i] < b[j])
        {
            ans += a[i] * (a[i + 1] * b[j + 1]); 
            b[j] -= a[i]; 
            i += 2; 
        }
        else
        {
            ans += b[j] * (a[i + 1] * b[j + 1]); 
            a[i] -= b[j]; 
            j += 2; 
        }
    }
    return ans; 
}
```