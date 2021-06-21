---
Created Time: Mar 01, 2021 5:17 PM
Do Date: Mar 01, 2021
Last edited time: Mar 06, 2021 3:59 PM
Points: 1300
Status: done
Tags: goldman sachs
---

# Get the nth string in the sequence

Get the nth string in the sequence → a, b, c, ..., z, aa, ab, ac, ..., az, ba, bb, bc, ..., bz, ..., za, zb, zc, ... zz, aaa, aab, aac, ...
---
```cpp
string func(int n)
{
	if (n == 0) return ""; 
	int rem = n % 26;
	int q = n / 26; 
	if (rem == 0)
	{
		rem = 1, q--; 
	}
	char ch = 'a' + rem - 1; 
	return func(q) + ch; 
}
```
Patterns: [String](String)[Number%20Theory](Number%20Theory.md)