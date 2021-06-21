---
Created Time: Feb 01, 2021 11:44 PM
Do Date: Feb 02, 2021
Last edited time: Feb 02, 2021 8:16 AM
Points: 1500
Pomos (25 mins): 1
Source: https://atcoder.jp/contests/abc190/tasks/abc190_d
Status: done
---

# D - Staircase Sequences

How many arithmetic progressions consisting of integers with a common difference of 1 have a sum of N?
constraints:
- $1 \le N \le 10^{12}$
- N is an integer.
---
let the sequence be $a, a + 1, a + 2,..., a + (n - 1)$. The sum will be $(2a + n - 1) * (n/2) = N$
$(2a + n - 1) * n = 2 * N$
We can check all the factors of 2N and equate it to n. The complexity will be $O(\sqrt n)$. 
```cpp
#include <iostream>
#include <vector>
using namespace std; 
int main()
{
	long long N; cin >> N; 
	vector<long long> factors;
	N *= 2; 
	for (long long i = 1; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			if (N / i == i) factors.push_back(i); 
			else factors.push_back(i), factors.push_back(N/i); 
		}
	}
	int ans = 0; 
	for (auto n : factors)
	{
		ans += ((N / n  - n + 1) % 2 == 0); 
	}
	cout << ans << endl;
	return 0; 
}
```
Patterns: 