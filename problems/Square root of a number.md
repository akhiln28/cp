---
Created Time: Jan 08, 2021 11:29 AM
Do Date: Jan 08, 2021
Last edited time: Jan 08, 2021 11:31 AM
Points: 800
Status: done
---

# Square root of a number

```cpp
double squareroot(int n)
{
		int x = 1; 
		while (true)
		{
				x = (x + n/x)/2; 
				if (precise) break;
		}
		return x; 
}
```
Patterns: 