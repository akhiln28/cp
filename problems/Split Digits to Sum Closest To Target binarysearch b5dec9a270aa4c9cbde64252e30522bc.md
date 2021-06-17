# Split Digits to Sum Closest To Target | binarysearch

Created Time: Feb 19, 2021 7:57 AM
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9
Points: 2000
Source: https://binarysearch.com/problems/Split-Digits-to-Sum-Closest-To-Target
Status: waiting

You are given a string `s` and an integer `target`. `s` represents a decimal number containing digits from `0` to `9`. You can partition `s` into as many parts as you want and take the sum of its parts. Afterwards, return the minimum possible absolute difference to `target`.

**Constraints**

- `1 ≤ n, target ≤ 1,000` where `n` is the length of `s`

### Example 1

****Input****

`s = "112"`
`target = 10`

****Output****

`3`

### **Explanation**

We can partition `s` into `"1" + "12"` which sums to `13` and `abs(13 - 10) = 3`.

### **Example 2**

****Input****

`s = "500"`

`target = 300`

****Output****

`200`

### **Explanation**

The best we can do is split `s` into just `"500"` and `abs(300 - 500) = 200`

### **Example 3**

****Input****

`s = "1"`

`target = 9`

****Output****

`8`

---