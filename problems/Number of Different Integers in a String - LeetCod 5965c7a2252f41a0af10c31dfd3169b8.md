# Number of Different Integers in a String - LeetCode

Created Time: Mar 27, 2021 10:16 PM
Do Date: Mar 27, 2021
Last edited time: Mar 28, 2021 8:27 AM
Pattern: https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1300
Source: https://leetcode.com/problems/number-of-different-integers-in-a-string/
Status: done

![LeetCode_Sharing.png](problems/Number%20of%20Different%20Integers%20in%20a%20String%20-%20LeetCod%205965c7a2252f41a0af10c31dfd3169b8/LeetCode_Sharing.png)

You are given a string `word` that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, `"a123bc34d8ef34"` will become `" 123  34 8  34"`. Notice that you are left with some integers that are separated by at least one space: `"123"`, `"34"`, `"8"`, and `"34"`.

Return *the number of **different** integers after performing the replacement operations on* `word`.

Two integers are considered different if their decimal representations **without any leading zeros** are different.

**Example 1:**

```
Input: word = "a123bc34d8ef34"
Output: 3
Explanation:The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
```

**Example 2:**

```
Input: word = "leet1234code234"
Output: 2
```

**Example 3:**

```
Input: word = "a1b01c001"
Output: 1
Explanation:The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.
```

**Constraints:**

- `1 <= word.length <= 1000`
- `word` consists of digits and lowercase English letters.

---

My implementation is kind of cumbersome. Below method is kind of neat. 

```python
for each ch in str:
	if (ch is digit): 
		cur_str += ch
	else if (cur_str.size()):
		map.insert(cur_str)
```

I think this can be used for any kind of tokenisation.