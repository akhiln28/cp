# Get the nth string in the sequence

Created Time: Mar 01, 2021 5:17 PM
Do Date: Mar 01, 2021
Last edited time: Mar 06, 2021 3:59 PM
Pattern: https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9
Points: 1300
Status: done
Tags: goldman sachs

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