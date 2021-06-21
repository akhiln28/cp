---
Created Time: Jan 14, 2021 9:00 AM
Last edited time: Mar 04, 2021 8:12 AM
Points: 1600
Pomos (25 mins): 3
Source: https://atcoder.jp/contests/abc188/tasks/abc188_d
Status: done
---

# D - Snuke Prime

![atcoder.png](D%20-%20Snuke%20Prime%207e1c4f3d41d94075830ce4509187a1f1/atcoder.png)
### Problem Statement
Snuke Inc. offers various kinds of services.
A payment plan called Snuke Prime is available.
In this plan, by paying C yen (the currency of Japan) per day, you can use all services offered by the company without additional fees.
You can start your subscription to this plan at the beginning of any day and cancel your subscription at the end of any day.
Takahashi is going to use N of the services offered by the company.
He will use the i-th of those services from the beginning of the ai-th day until the end of the bi-th day, where today is the first day.
Without a subscription to Snuke Prime, he has to pay ci yen per day to use the i-th service.
Find the minimum total amount of money Takahashi has to pay to use the services.
---
Each interval $[a_i, b_i] \rightarrow c_i$  can be expanded to 
1. $[a_i, c_i]$ → cost increases at day $a_i$ 
2. $[b_{i + 1}, -c_i]$ → cost decreases at day $b_{i + 1}$
We can sort the expaned values according to the times. And calculate the total cost. 
```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
	long long n, C; cin >> n >> C;
	map<int, long long> mp; 
	for (int i = 0; i < n; i++)
	{
		int a, b, c; 
		cin >> a >> b >> c; 
		// storing the expanded intervals in a map
		mp[a] += c; 
		mp[b + 1] -= c; 
	}
	long long ans = 0, prev = 0, cost = 0; 
	for (auto [time, c] : mp)
	{
		ans += (time - prev) * min(cost, C);
		prev = time;
		cost += c;
	}
	cout << ans << endl;
	return 0;
}
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Intervals](Intervals.md)