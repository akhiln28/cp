# Count Sorted Vowel Strings - LeetCode

Created Time: Dec 19, 2020 4:12 PM
Do Date: Jan 29, 2021
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1200
Pomos (25 mins): 3
Source: https://leetcode.com/problems/count-sorted-vowel-strings/
Status: done

Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`*) and are **lexicographically sorted**.*

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

**Example 2:**

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

**Example 3:**

```
Input: n = 33
Output: 66045
```

**Constraints:**

- `1 <= n <= 50`

---

$$count(n, 5) = count(n - 1, 5) + count(n - 1, 4) + count(n - 1, 3) + count(n - 1, 2) + count(n - 1, 1) + count(n - 1, 0)$$

We can write similar expressions for count(n, 4) and so on. 

```cpp
class Solution {
public:
    map<pair<int, int>, int> mp; // memoization
    int func(int n, int c)
    {
        if (n == 1) return c; 
        if (mp.find({n, c}) != mp.end()) return mp[{n, c}]; 
        int ans = 0; 
        for (int i = c; i >= 1; i--)
        {
            ans += func(n - 1, i); 
        }
        mp[{n, c}] = ans; 
        return ans; 
    }
    int countVowelStrings(int n) {
        return func(n, 5); 
    }
};
```

### Another O(1) solution,

### **Solution 4: Combination number**

Now we have `n` characters, we are going to insert 4 `l` inside.We can add in the front, in the middle and in the end.How many ways do we have?

For the 1st `l`, we have `n+1` position to insert.

For the 2nd `l`, we have `n+2` position to insert.

For the 3rd `l`, we have `n+3` position to insert.

For the 4th `l`, we have `n+4` position to insert.

Also 4 `l` are the same,there are `(n + 1) * (n + 2) * (n + 3) * (n + 4) / 4!` ways.

The character before the 1st `l`, we set to `a`.The character before the 2nd `l`, we set to `e`.The character before the 3rd `l`, we set to `i`.The character before the 4th `l`, we set to `o`.The character before the 5th `l`, we set to `u`.

We get the one result for the oringinal problem.

Time `O(1)`Space `O(1)`